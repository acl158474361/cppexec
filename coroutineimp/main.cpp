#include <stdio.h>
#include <memory>
#include "schedule.h"
#include "coroutine.h"

class logic1 :public co_routine{
    void co_process(){
        puts("1");
        yield();
        puts("4");
        yield();
        puts("7");
    }
};

class logic2 :public co_routine{
    void co_process(){
        puts("2");
        yield();
        puts("5");
        yield();
        puts("8");
    }
};

class logic3 :public co_routine{
    void co_process(){
        puts("3");
        yield();
        puts("6");
        yield();
        puts("9");
    }
};

int main(){
    std::shared_ptr<co_routine> ct1(new logic1());
    std::shared_ptr<co_routine> ct2(new logic2());
    std::shared_ptr<co_routine> ct3(new logic3());

    ct1->setid(1);
    ct2->setid(2);
    ct3->setid(3);

    singleton_schedule::getinstance()->co_routine_new(ct1.get());
    singleton_schedule::getinstance()->co_routine_new(ct2.get());
    singleton_schedule::getinstance()->co_routine_new(ct3.get());

    singleton_schedule::getinstance()->resume(1);
    singleton_schedule::getinstance()->resume(2);
    singleton_schedule::getinstance()->resume(3);
    singleton_schedule::getinstance()->resume(1);
    singleton_schedule::getinstance()->resume(2);
    singleton_schedule::getinstance()->resume(3);

    int count = singleton_schedule::getinstance()->has_co_routine();
    printf("%d\n",count);
    return 0;


}