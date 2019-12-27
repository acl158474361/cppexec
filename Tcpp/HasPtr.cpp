#include <string>
#include <iostream>
class HasPtr{
    public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)) {}
    HasPtr(const HasPtr &r):ps(new std::string(*r.ps)) {}
    HasPtr& operator=(const HasPtr &rhs);
    std::string* getPs(){ return ps; }
    ~HasPtr() {delete ps;}
    private:
    std::string *ps;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    if(this != &rhs){
        delete ps;
        ps = new std::string(*rhs.ps);
    }
    return *this;
}

class HasPtr_p{
    public:
    HasPtr_p(const std::string &s = std::string()):ps(new std::string(s)), i(new int(1)) {}
    HasPtr_p(const HasPtr_p &r):ps(r.ps), i(r.i) { ++(*i); }
    HasPtr_p& operator=(const HasPtr_p &rhs);
    std::string* getPs(){ return ps; }
    ~HasPtr_p();
    private:
    std::string *ps;
    int *i;
};

HasPtr_p& HasPtr_p::operator=(const HasPtr_p &rhs){
    ++*rhs.i; //先递增右边已经处理了自赋值情况
    if(--*i == 0){
        delete ps;
        delete i;
    }
    ps = rhs.ps;
    i = rhs.i;
    return *this;
}

HasPtr_p::~HasPtr_p(){
    if(--*i == 0){
        delete ps;
        delete i;
    }
}


int main(void){
    
    HasPtr a(std::string("aaaa"));
    {   
        HasPtr b(std::string("bbbb"));
        a = b;
    }
    std::cout << *a.getPs() << std::endl;
    HasPtr_p ap(std::string("aaaa"));
    {
        HasPtr_p bp(std::string("bbbb"));
        ap = bp;
    }
    std::cout << *ap.getPs() << std::endl;
    return 0;

}