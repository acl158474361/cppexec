#include "Animal.h"

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

void print(const Bear&) 
{
	cout << "print(const Bear&)" << std::endl;

}

void highlight(const Endangered&)
{
	cout << "highlight(const Endangered&)" << std::endl;
}

ostream& operator<<(ostream &os, const ZooAnimal&)
{
	return os << "ZooAnimal output operator" << endl;
}

int main(void){
    Bear *pb = new Panda("ying_yang");
    pb->print();
    pb->toes();
    delete pb;

    cout << "----------------------------------" <<endl;
    Endangered *pe = new Panda("ying yang");
    pe->print();
    pe->highlight();
    delete pe;

    cout << "----------------------------------" <<endl;
    ZooAnimal *pz = new Panda("ying_yang");
    pz->print();
    delete pz;
}


