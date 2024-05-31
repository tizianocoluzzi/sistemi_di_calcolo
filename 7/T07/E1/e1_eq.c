#include "e1.h"

int binsearch(int *v, int n, int x){
    int b = x;//pushl
    int* bi = v;
    int d = 0;
    int c = n;
L:; int a = 0;
    if(d >= c) goto R;
    a += d;
    a += c;
    a = a >> 1;
    if(bi[a] != b) goto N;
    a = 1;
    goto R;
N:  if(bi[a] <= b) goto E;
    c = a;
    goto L;
E:  a++;
    d = a;
F:  goto L;
R:  return a;
}