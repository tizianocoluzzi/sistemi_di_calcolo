#include "e2.h"
#define STRIDE 64
long f_opt(const short *v, unsigned n){
 
    long x = 0;
    unsigned i, j;
    for (i=0; i<n; i+=STRIDE)
        for (j=0; j<STRIDE; ++j) x += v[i+j];
    return x;
}
