#include <stdio.h>

class B{
    public:
    B():b(300){}
    int b = 10;
};

class C:public B{
    public:
    int c = 20;
    C(int c):c(c){};
};

int main(){
    C c(20);
    printf("%d\n", c.b);

}
