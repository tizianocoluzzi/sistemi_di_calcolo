#include "e3.h"
#include <stdio.h>
// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

char *my_strpbrk(const char *s1, const char *s2){
    char* b = s2;
    while(*s1){
        while(*s2){
            printf("%c", *s1);
            printf(" %c\n", *s2);
            if(*s1 == *s2){
                return s1;
            }
            ++s2;
        }
        s2 = b;
        ++s1;
    }
    return NULL;
}