#include <stdio.h>

class B{
    public:
    int pub_mem = 10;
};

class D:protected B{

};

class D2:public D{
    public:
    int f(){return pub_mem;}
};

int main(int argc, char* argv[]){
    D2 d;
    D d1;
    d1.pub_mem;
    printf("%d\n", d.f());
}
