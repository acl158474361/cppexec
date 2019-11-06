#include <assert.h>
#include "schedule.h"

schedule::schedule(){

}
schedule::~schedule(){

}

void schedule::co_routine_entry(void *crt){
    ( (co_routine*)crt)->setstate(RUNNING);
    ( (co_routine*)crt)->co_process();
    ( (co_routine*)crt)->setstate(FREE);
}


void schedule::co_routine_new(co_routine *crt){
    int id = crt->getid();
    co_state state = co_state(crt->getstate());
    assert(id != 0);
    assert(state == FREE);

    if(crtpool[id]!=nullptr){
        crtmap::iterator it = crtpool.find(id);
        crtpool.erase(it);
    }

    getcontext(&(crt->ctx));
    crt->ctx.uc_stack.ss_sp = stack;
    crt->ctx.uc_stack.ss_size = DEFAULT_STACK_SIZE;
    crt->ctx.uc_flags = 0;
    crt->ctx.uc_link = &mainCtx;
    crtpool[id] = crt;

    makecontext(&crt->ctx,(void (*)(void))co_routine_entry,1,(void*)crt);
    swapcontext(&mainCtx,&crt->ctx);

}


void schedule::resume(int id){
    if(crtpool[id]!=nullptr){
        crtpool[id]->resume();
    }
}

int schedule::has_co_routine(){
    int count =0;
    crtmap::iterator it;
    for(it = crtpool.begin();it!=crtpool.end();++it){
        if(it->second->getstate()!=FREE){
            count++;
        }else{
            it = crtpool.erase(it); //???
            it--;
        }
    }
    return count;
}

void schedule::remove(int id){
    if(crtpool[id]!=nullptr){
        crtpool.erase(crtpool.find(id));
    }
}