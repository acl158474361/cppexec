#include <cstdio>

void c(){
    int c = 10;
    printf("c 0x%lx %ld\n",&c,&c);
}

int main(){
    int a = 10;
    int b = 12;
    
    printf("a 0x%lx %ld\n",&a,&a);
    printf("b 0x%lx %ld\n",&b,&b);
    c();

    
}