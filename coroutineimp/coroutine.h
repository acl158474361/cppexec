#ifndef COROUTINE_H_
#define COROUTINE_H_
#define DEFAULT_STACK_SIZE (1024*1024)
#include <stdio.h>
#include <string.h>
#include <ucontext.h>

enum co_state {FREE = 0,RUNNING=1,SUSPEND=2};

class co_routine{
public:
    char *buffer;
    ucontext_t ctx;
private:
    int stack_size;
    int cap;
    int id;
    co_state state;


public:
    co_routine();
    virtual ~co_routine();

    virtual void co_process();

    void resume();

    int getid() const{
        return id;
    }

    void setid(int _id){
        id = _id;
    }

    int getstate() const{
        return state;
    }

    void setstate(co_state _state){
        state = _state;
    }
protected:
    void yield();
    void save_stack();
    void reload_stack();
};

#endif