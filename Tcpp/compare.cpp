#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>


template<typename T>
int compare(const T &v1,const T &v2){
    if(v1<v2)
        return -1;
    if(v2<v1)
        return 1;
    return 0;
}

template<unsigned M,unsigned N>
int compare(const char(&v1)[M],const char(&v2)[N]){
    //v1 和 v2 是字符数组引用
    //传递到strcmp 就变成指针
    return strcmp(v1,v2);
}


template<typename T,unsigned M>
inline unsigned getlen(const T(&)[M]){
    return M;
}


/* template<typename T,unsigned M,unsigned N>
int compare( const T (*v1)[M],const T (*v2)[N]){
    数组传递过来是指针 所以这个const 修饰的实际上是const int*
      但是 const int **p = v1 语法错误 
      编译器提示 cannot convert ‘const int (*)[2]’ to ‘const int**’ in initialization
      但是 const int *p = *v1 语法没有错误
      int *p = *v1 有语法错误 
      编译器提示 invalid conversion from ‘const int*’ to ‘int*’

    
    const T *p1 = *v1,*p2 = *v2;
    int tag = 0;
    unsigned minval = min(M,N);
    
    for (unsigned i = 0;i<minval&&(tag == 0);++i){
        if(*(p1+i) < *(p2+i))
            tag = -1;
        else if(*(p2+i) < *(p1+i))
            tag = 1;
        
    }
    if(tag == 0){
        if(M<N){
            tag = -1;
        }else if(N<M){
            tag = 1;
        }
    }
    return tag;
} */
int main(){
    
    std::cout << getlen("zhou")<< std::endl;
    
}