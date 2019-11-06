#include <iostream>
#include <vector>
#include <chrono>

#include "ThreadPool.h"

int main()
{
    std::mutex var_mutext;
    
    ThreadPool pool(4);
    std::vector< std::future<int> > results;
    
    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i,&var_mutext] {
                {
                std::unique_lock<std::mutex> lock(var_mutext);
                std::cout << "hello " << i << std::endl;
                std::cout << "world " << i << std::endl;
                return i*i;
                }
            })
        );
    }
    
    pool.all_join();
    
    for(auto &&result : results){
            std::cout << result.get() <<std::endl;
     }
    
    return 0;
}
