#include <pthread.h>
#include <stdlib.h>

#include "e3.h"
#include <pthread.h>
#include <stdio.h>

unsigned int *shared_array;

// Inserire qui la soluzione

void* fun(void* args){
    int it = ((int*)args)[0];
    int val = ((int*)args)[1];
    int idx = ((int*)args)[2];
    printf("indice: %d\n", idx);
    shared_array[idx] = it*val; 
    return NULL;
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val){
    shared_array = calloc(th, sizeof(int));
    //parte dei thread
    pthread_t* t = malloc(th * sizeof(pthread_t));
    int ** args = malloc(th*sizeof(int*));
    for(int i = 0; i < th; i++){
        *args = malloc(sizeof(int) * 3);
        (*args)[0] = it;
        (*args)[1] = val;
        (*args)[2] = i;
        pthread_create(&(t[i]), NULL, fun, (void*) *args);
        args++;
    }
    for(int i = 0; i< th; i++){
        pthread_join(t[i], NULL);
    }
    unsigned int res = 0;
    for(int i = 0; i < th; i++){
        res += shared_array[i];
    }
    return res;
}
