#include <stdio.h>
int count_digits(const char *s){
    char* d = s;
    int a = 0;
L:  if(*d == 0) goto R;
    int c = (*d >= 48);
    if(c - 1 != 0) goto E;
    c = *d <= 57;
    a += c;
E:
    d++;
    goto L;
R:
    return a;
}
