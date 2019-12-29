#include <stdio.h>
#include <math.h>

#include <future>
#include <functional>
#include <thread>


int f(int x, int y) { return std::pow(x, y); }

void task_lambda(){
    std::packaged_task<int(int, int)> task([](int a, int b) ->int { return std::pow(a,b); });
    std::future<int> result = task.get_future();
    std::function<int(int, int)> func(f);
    task(2, 9);
    printf("func\t%d\n", func(2, 9));
    printf("task_lambda\t%d\n", result.get());
}

void task_bind(){
    
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
    task();
    printf("task_lambda\t%d\n", result.get());
}

void task_thread(){
    std::packaged_task<int(int, int)> task(f);
    std::future<int> result = task.get_future();
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
    printf("task_lambda\t%d\n", result.get());
}

void thr_f1(){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    for(int i = 0; i < 10; ++i){
        printf("%d\n", i);
    }
}

int main(void){
    task_lambda();
    task_bind();
    task_thread();
    std::thread thr(thr_f1);
    std::thread thr1(std::move(thr));
    printf("%d\n", thr.joinable());
    printf("%d\n", thr1.joinable());
    thr1.join();
}