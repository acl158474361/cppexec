#include <cstdio>

int main(){
    const char a[12] = "hello,world";
    const char b[12] = "hello,world";
    const char *ap = "hello,world";
    const char *bp = "hello,world"; 
    printf("a 0x%lx %ld\n",a,a);
    printf("b 0x%lx %ld\n",b,b);
    printf("ap 0x%lx %ld\n",ap,ap);
    printf("bp 0x%lx %ld\n",bp,bp);

    
}