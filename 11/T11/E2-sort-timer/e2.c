#include "e2.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
int max, i;
static void do_sort(int *v, int n) {
    int j;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

void handler(int sig){
    printf("%3.1f%%\n", 100.0*i/max);
    ualarm(500000, 0);
}

void sort(int *v, int n) {
    max = n;
    struct sigaction act = { 0 };
    act.sa_handler = handler;

    ualarm(500000, 0);
    int res = sigaction(SIGALRM, &act, NULL);
    do_sort(v, n);
    
    act.sa_handler = SIG_IGN;
    res = sigaction(SIGALRM, &act, NULL);
}

