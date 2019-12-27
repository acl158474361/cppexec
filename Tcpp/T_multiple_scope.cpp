#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;

struct Base1{
    void print(int) const { cout << "Base1.print" << endl; }
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};

struct Base2{
    void print(double) const { cout << "Base2.print" << endl; };
protected:
    double fval;
private:
    double dval;
};

struct Derived:public Base1{
    void print(std::string) const { cout << "Derived.print" << endl; }
protected:
    std::string sval;
    double dval;
};

struct MI:public Derived, public Base2{
    void print(std::vector<double>) { cout << "MI.print" << endl; }
protected:
    int *ival;
    std::vector<double> dvec;
};

int main(void){
    MI mi;
    //mi.print(42); 错误，没有匹配的函数，因为MI中的print覆盖了基类的所有print
    mi.print(static_cast<std::vector<double>>(42)); //vector的接受容器大小的构造函数是explicit的
}