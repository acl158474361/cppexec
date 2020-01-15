#include <stdio.h>


int main(void){
    printf("%-*d\n", 10, 1234567890);
    printf("%2$-*1$.*3$s\n", 4, "aaaaaaaaaaaaaaaa", 9); //这种说明先指定需要转换的参数 %2$ 说明转换的参数为第二个
    printf("%2$-*1$.*3$s\n", 4, "a", 9);                //后面按照顺序说明[flags][fldwidth][precision][lenmodifier]convtype 
                                                        //flags:- ; fldwidth:*1$ ; precision:.*3$ ; lenmodifier:无 ; convtype:s
}