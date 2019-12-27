#include <stdio.h>


#include <string>
#include <iostream>
#include <type_traits>
#include <utility>



template<typename T>
void print_template(const T &){
    printf("%s\n", "const T&");
    T a = new std::string("aaa");
    std::cout << *a << std::endl;
}

template<typename T>
void f1(T &){

}

template<typename T>
void f2(const T &){

}

template<typename T>
void f3(T &&){

}

template<typename T>
void print_template(T *){
    printf("%s\n", "T*");
}


template<typename T>
typename std::remove_reference<T>::type&& move_1(T &&t){
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2){
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2){
    f(t1, t2);
}

template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2){
    f(t1, t2);
}

void f(int v1, int &v2){
    std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&v1, int &v2){
    std::cout << v1 << " " << ++v2 << std::endl;
}


int main(int argc, char* argv[]){
    const std::string str("abcde");
    const std::string *p_str = &str;
    print_template(p_str);

    int i = 0;
    f1(i);

    const int ci = 10;
    f1(ci);

    f2(i);

    f2(ci);

    f2(5);

    f3(i);

    f3(ci);

    f3(5);

    std::string s1("hi"), s2;
    s2 = move_1(std::string("bye!"));
    s2 = move_1(s1);

    int j = 4;
    f(1,j);
    printf("%d\n", j);

    j = 4;
    flip1(f, 1, j);
    printf("%d\n", j);


/* template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2){
    f(t1, t2);
} */
    j = 4;
    flip2(f, 1, j);
    printf("%d\n", j);

    j = 4;
    flip(g, 100 ,j);
    printf("%d\n", j);
}