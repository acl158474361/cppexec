#include <stdio.h>

struct Base{
    void bar(int) { printf("Base::bar\n"); }
protected:
    int ival = 1;
};

struct Derived1:virtual public Base{
    void bar(char) { printf("Derived1::bar\n"); }
    void foo(char) { printf("Derived1::foo\n"); }
protected:
    char cval = 'a';
};

struct Derived2:virtual public Base{
    void foo(int) { printf("Derived2::foo\n"); }
protected:
    int ival = 2;
    char cval = 'b';
};

class VMI:public Derived1, public Derived2{
    public:
    void func();
};

inline void VMI::func(){
    printf("%d\n", ival);
    bar('c');
    bar(10);
    
}

int main(void){
    VMI v;
    v.func();
}



