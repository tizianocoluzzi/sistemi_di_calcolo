#include <stdio.h>
int is_suffix(const char* s1, const char* s2){
    const char *edx = s1;
    const char *ecx = s2;
    char bl; // ricorda prologo e epilogo
    char al;
L1:
    al = *edx;
    if (al == 0) goto E1;
    ++edx;
    goto L1;
E1:
    edx++;   
L2: 
    al = *ecx;
    if (al == 0) goto E2;
    ++ecx;
    goto L2;
E2:
    ecx++; 
    //while (s1 != edx && s2 != ecx && *(--edx) == *(--ecx));
L3:
    --edx;
    --ecx;
    if(s1 == edx) goto E3;
    if(s2 == ecx) goto E3;
    al = *edx;
    if(al !=  *ecx) goto E3;
    goto L3;
E3:;
    int eax = s1 == edx;
    bl = *edx;
    if(bl != *ecx) eax = 0;
    return eax;
}