#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* STRCAT(const char* lchar, const char* rchar){
    char* buf = (char*)malloc((strlen(lchar)+strlen(rchar)+1)*sizeof(char));
    if(buf == NULL){
        perror(" ERROR");
        return buf;
    }

    strncpy(buf, lchar, strlen(lchar));
    strncat(buf, rchar, strlen(rchar));

    return buf; 
}



int main(void){
    const char *a = "bbbb";
    const char *b = "aaaa";
    printf("%s\n", STRCAT("cccc","dddd"));
}