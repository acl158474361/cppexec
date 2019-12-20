#include <iostream>
using namespace std;

class T{
public:
    ~T(){cout << "in destruction" <<endl;}

    
    
};


int main(){

    {
        T a;
    }
    cout << "out of block" << endl;
}