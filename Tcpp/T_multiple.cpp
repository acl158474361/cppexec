#include <iostream>

using std::cout;
using std::endl;

class A{
    public:
    A(){ std::cout << "A::A()" << std::endl; }
};

class B:public A{
    public:
    B(){ std::cout << "B::B()" << std::endl; }
};

class C:public B{
    public:
    C(){ std::cout << "C::C()" << std::endl; }
};

class X{
    public:
    X(){ std::cout << "X::X()" << std::endl; }
};

class Y{
    public:
    Y(){ std::cout << "Y::Y()" << std::endl; }
};

class Z:public X, public Y{
    public:
    Z(){ std::cout << "Z::Z()" << std::endl; }
};

class MI:public C, public Z{
    public:
    MI(){ std::cout << "MI::MI()" << std::endl; }
};

class D:public X, public C{
    public:
    D(){ std::cout << "X::X()" << std::endl; }
};


class Base1{
    public:
        Base1(){ cout << "Base1::Base1()" << endl; }
        virtual ~Base1(){ cout << "Base1 dtor" << endl; }
        virtual void print() { cout << "Base1::print()" << endl; }
};

class Base2{
    public:
        Base2(){ cout << "Base2::Base2()" << endl; }
        virtual ~Base2(){ cout << "Base2 dtor" << endl; }
        virtual void print() { cout << "Base2::print()" << endl; }
};

class D1: public Base1{
    public:
        D1(){ cout << "D1::D1()" << endl; }
        virtual ~D1(){ cout << "D1 dtor" << endl; }
        virtual void print() { cout << "D1::print()" << endl; }
};

class D2: public Base2{
    public:
        D2(){ cout << "D2::D2()" << endl; }
        virtual ~D2(){ cout << "D2 dtor" << endl; }
        virtual void print() { cout << "D2::print()" << endl; }
};

class MI2:public D1, public D2{
    public:
    MI2(){ std::cout << "MI2::MI2()" << std::endl; }
    virtual ~MI2(){ cout << "MI2 dtor" << endl; }
    virtual void print() { cout << "MI2::print()" << endl; }
};



int main(void){
 /*    D *pd = new D();
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd; */

    /* Base1 *pb1 = new MI2();
    Base2 *pb2 = new MI2();

    D1 *pd1 = new MI2();
    D2 *pd2 = new MI2();

    cout << "-------------------------" <<endl;
    delete pd2; */

    
}











