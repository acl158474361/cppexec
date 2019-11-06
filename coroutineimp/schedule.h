#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <stdio.h>
#include <map>
#include <ucontext.h>
#include "coroutine.h"
#include "singleton.h"

typedef std::map<int,co_routine*> crtmap;

class schedule{
public:
    ucontext_t mainCtx;
    char stack[DEFAULT_STACK_SIZE];
private:
    crtmap crtpool;


public:
    schedule();
    virtual ~schedule();

    static void co_routine_entry(void *crt);

    void co_routine_new(co_routine *crt);

    void resume(int id);

    int has_co_routine();

    void remove(int id);

    char* getstack_bottom(){
        return stack + DEFAULT_STACK_SIZE;
    }
};

typedef singleton<schedule> singleton_schedule;

#endif