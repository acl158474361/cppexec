#include <ucontext.h>
#include <stdio.h>

void func1(void *arg){
    printf("func1 \n");
}
int main(void){
    char stack[1024*128];
    ucontext_t child,main;
    getcontext(&child);

    child.uc_stack.ss_sp = stack;
    child.uc_stack.ss_size = sizeof(stack);
    child.uc_stack.ss_flags = 0;
    child.uc_link = &main;
    makecontext(&child,(void (*)(void))func1,0);
    swapcontext(&main,&child);
    printf("main \n");
    return 0;
}