#include <stdio.h>

class B{
    protected:
    int prot_mem = 100;
};

class D:private B{
    public:
    using B::prot_mem;
};

int main(){
    D d;
    printf("%d\n", d.prot_mem);
}