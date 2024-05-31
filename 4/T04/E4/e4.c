// aa\0
// aaaaaa

#include <stdio.h>
int count_substrings(const char* s, const char* sub){
    int cont = 0;
    const char* mem = sub;
    const char* s1 = s;
    int l = 0;
    if(!*s && !*sub) return 1;
    int idx = 0;
    while(*s){
        //printf("%c %c\n", *sub, *s);
        if(*s == *sub){
            printf("punto uguale\n");
            sub++;
            if(!*sub){
                //printf("stringa uguale\n");
                sub = mem;
                cont++;
                idx+=1;
                //printf("ricomincio da %d e count %d, next %c\n", idx, cont, *(s1+idx));
                s = (s1 +idx-1);
            }
        }
        else{
            sub=mem;
            idx++;
        }
        s++;
    }
    return cont;
}