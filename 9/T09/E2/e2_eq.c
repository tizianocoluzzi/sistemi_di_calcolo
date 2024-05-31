#include "e2.h"

int crc32b(char *bytes, int n) {
    char* ebx = bytes;
    //int ebp = ~0; // operazione: not
    int ebp = -1;
    int edi = n;
L:    
    if (edi <= 0)  goto R;
        edi -= 1;
        int ecx; //da pushare in memoria
        int edx = *ebx; 
        ebx++;
        int eax;
        eax = ebp;
        eax = eax ^ edx;
        eax = eax & 255;
        //preparare due parametri
        get_constant(&ecx, eax);
        eax = ebp;
        eax = eax >> 8;
        ebp = ecx;
        ebp = ebp ^ eax;
        goto L;
R:;
    int a = ebp;
    a = a ^ -1;
    return a;
}