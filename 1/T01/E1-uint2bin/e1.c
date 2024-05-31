// Inserire la soluzione qui...
#include <stdio.h>
void uint2bin(unsigned x, char bin[32]){
    //printf("%x\n", x);
    int a = (int) x;
    printf("risultato: ");
    for(int i = 0; i < 32; i ++){
        if(a & 1){ //si vede se il bit meo significativo è 0 o 1
            bin[31-i] = '1';
        }
        else{
            bin[31-i] = '0';
        }
        a = a >> 1; //scorrimento a destra
        printf("%c", bin[32-i]);
    }
    printf("\n");
}

