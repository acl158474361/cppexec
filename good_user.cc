#include "b.h"
#include <cstdio>

void f(B *) { printf("int first\n"); }
void f(void *) { printf("in second\n"); }
void test(D *x) { f(x); } // calls f(B*)

int main()
{
    D *d;
    test(d);
}