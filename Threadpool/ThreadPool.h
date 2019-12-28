#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <type_traits>

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
    void all_join();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;
    
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};
 
// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    :   stop(false)
{
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
            //Thread 的一个构造函数 传入一个函数对象 (即可调用对象)
            [this]
            {
                //这个调用对象会不断从 taskqueue里面抽取任务 执行 所以放在一个for 循环里面
                //调用对象 使用条件变量等待 条件为true ( this->stop || !this->tasks.empty() )
                //当stop 为true 也就是线程池停止 或者线程池没有停止并且taskqueue里面还有任务时 
                //wait 函数返回
                for(;;)
                {
                    std::function<void()> task;

                    {
                        //unique_lock 的析构函数会自动释放锁
                        //因为unique_lock在一个块中，离开块会自动析构 释放锁
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty()) //stop后仍旧把之后的任务全部完成
                            return;
                        task = std::move(this->tasks.front());  //使用移动构造函数
                        this->tasks.pop();
                    }

                    task();
                }
            }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    //返回一个 packaged_task 的智能指针 
    //packaged_task 里面是一个可调用对象 所以return_type后面要加()
    //通过bind 函数 制造一个可调用对象(函数对象)
    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");
        //tasks emplace 的是一个lamda 所以肯定符合void()
        tasks.emplace([task](){ (*task)(); });
    }
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers){
        if(worker.joinable())
        worker.join();
    }
}

inline void ThreadPool::all_join(){
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers)
        worker.join();
}

#endif
