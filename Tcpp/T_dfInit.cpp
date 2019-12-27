#include <stdio.h>

class B{
    public:
    B():b(100){ printf("B::B()\n"); }
    int b = 10;
    int b1 = 20;
};

class C:public B{
    public:
    int c = 20;
    C(int c):c(c){ printf("C::C()\n"); };
};

int main(){
    C c(20);
    printf("%d\n", c.b); //基类部分调用基类的默认构造函数，如果有基类成员没有被基类默认构造函数初始化，则使用基类的类内初始值
    printf("%d\n", c.b1); //如果基类的类内初始值为空（如果这个成员是类类型的成员，则调用类的默认构造函数初始化它）否则，成员的值是未定义的

}
