#include "e4.h"

int lcm(int x, int y){
    int eax = y;
    int edx;
    if(x > eax){ //movcc
        eax = x;
    }
L:;
    edx = eax;
    edx = edx >> 31; //resta solo l'ultimo bit
    edx = eax % x;
    if(edx != 0) goto E;
    edx = edx >> 31;
    edx = eax % y;
    if(edx != 0) goto E;
    goto R;
E:
    eax++;
    goto L;
R:
    return eax;
}
