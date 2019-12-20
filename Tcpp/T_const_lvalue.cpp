#include <utility>
#include <iostream>

void t_lvalue(int &&i){
    std::cout << "in first block" <<std::endl;
}

void t_lvalue(const int &i){
    std::cout << "in second block" <<std::endl;
}

int main(){
    const int&& p = 10;
    t_lvalue(10);
    t_lvalue(p);

}