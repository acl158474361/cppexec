#include <stdio.h>
#include <math.h>

#include <future>
#include <functional>
#include <thread>


int f(int x, int y) { return std::pow(x, y); }

void task_lambda(){
    std::packaged_task<int(int, int)> task([](int a, int b) ->int { return std::pow(a,b); });
    std::future<int> result = task.get_future();
    task(2,9);
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
int main(void){
    task_lambda();
    task_bind();
    task_thread();
}