#include <assert.h>
#include "coroutine.h"
#include "schedule.h"

co_routine::co_routine()
    :id(0),state(FREE),cap(0),stack_size(0),buffer(nullptr)
{

}

co_routine::~co_routine(){
    delete[] buffer;
}

void co_routine::co_process(){

}

void co_routine::resume(){
    if(state == SUSPEND){
        reload_stack();
        state = RUNNING;
        swapcontext(&(singleton_schedule::getinstance()->mainCtx),&ctx);
    }
}

void co_routine::yield(){
    if(state == RUNNING){
        save_stack();
        state = SUSPEND;
        swapcontext(&ctx,&(singleton_schedule::getinstance()->mainCtx));
    }
}

void co_routine::save_stack(){
    char *stack_bottom = singleton_schedule::getinstance()->getstack_bottom();//高地址 栈顶
    char dumy = 0; //协程的栈空间在调度器的stack里面 栈从高地址向低地址生长
    assert(stack_bottom-&dumy <= DEFAULT_STACK_SIZE);
    if(cap < stack_bottom-&dumy){ 
        //stack_bottom-&dumy 代表协程已经使用的栈空间大小
        //如果cap 小于这个值 就说明缓存空间大小要重新分配
        if(buffer){
            delete [] buffer;
        }
        cap = stack_bottom-&dumy;
        buffer = new char[cap];
    }
    stack_size = stack_bottom-&dumy;
    memcpy(buffer,&dumy,stack_size); //从低地址向高地址拷贝

}

void co_routine::reload_stack(){
    //从低地址向高地址拷贝
    memcpy(singleton_schedule::getinstance()->getstack_bottom()-stack_size,
    buffer,stack_size);
}

