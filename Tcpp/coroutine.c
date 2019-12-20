#include <ucontext.h>
#include <stdio.h>
#include <unistd.h>

const int MAX_COUNT = 8;
//static ucontext_t uc[3];
static ucontext_t uc[4];
static int first_entry = 0;
void ping();
void pong();

void ping(int count)
{
    
    while (count < MAX_COUNT)
    {
        printf("ping %d\n", count++);
        sleep(1);
        swapcontext(&uc[1], &uc[2]);
    }
}

void pong(int count)
{
    
    while (count < MAX_COUNT)
    {
        printf("pong %d\n", count++);
        sleep(1);
        swapcontext(&uc[2], &uc[1]);
    }
}

char st1[8192];
char st2[8192];

int main(int argc, char *argv[])
{
    
    printf("times %d \n",MAX_COUNT);
    getcontext(&uc[1]);
    getcontext(&uc[2]);

    printf("begin \n");

    uc[1].uc_link = &uc[0];
    uc[1].uc_stack.ss_sp = st1;
    uc[1].uc_stack.ss_size = sizeof(st1);
    makecontext(&uc[1],(void(*)(void))ping,1,3);


    uc[2].uc_link = &uc[0];
    uc[2].uc_stack.ss_sp = st2;
    uc[2].uc_stack.ss_size = sizeof(st2);
    makecontext(&uc[2],(void(*)(void))pong,1,4);


    swapcontext(&uc[0],&uc[1]);
    printf("end \n");
    return 0;
   


    /*
   printf("times %d \n",MAX_COUNT);
    getcontext(&uc[1]);
    getcontext(&uc[2]);
    getcontext(&uc[3]);
    printf("begin \n");

    uc[1].uc_link = &uc[3];
    uc[1].uc_stack.ss_sp = st1;
    uc[1].uc_stack.ss_size = sizeof(st1);
    makecontext(&uc[1],ping,0);


    uc[2].uc_link = &uc[3];
    uc[2].uc_stack.ss_sp = st2;
    uc[2].uc_stack.ss_size = sizeof(st2);
    makecontext(&uc[2],pong,0);


    swapcontext(&uc[0],&uc[1]);
    printf("end \n");
    return 0;
    */

    /*
    printf("times %d \n", MAX_COUNT);
    getcontext(&uc[1]);
    getcontext(&uc[2]);
    getcontext(&uc[3]);
    printf("begin \n");
    printf("begin , is_first_entry %d \n", first_entry);

    if (first_entry == 0)
    {
        first_entry++;
        uc[1].uc_link = &uc[3];
        uc[1].uc_stack.ss_sp = st1;
        uc[1].uc_stack.ss_size = sizeof(st1);
        makecontext(&uc[1], ping, 0);

        uc[2].uc_link = &uc[3];
        uc[2].uc_stack.ss_sp = st2;
        uc[2].uc_stack.ss_size = sizeof(st2);
        makecontext(&uc[2], pong, 0);

        swapcontext(&uc[0], &uc[1]);
        
    }
    printf("end \n");
    return 0;
    */
}
