#include <stdio.h>


#define MACRO(format) ( fprintf(stdout,"%s:%d: expect: " format " actual: " format "\n",__FILE__,__LINE__) )
int main(void){
   MACRO("aaaa");
}