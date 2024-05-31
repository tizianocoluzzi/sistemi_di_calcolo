#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **l, short elem){
    //c equivalente completamente sballato nei registri perche
    //non avevo considerato la malloc
    node_t *c = *l;
    short dl = elem;
    node_t *ebx = malloc(sizeof(node_t));
    int a = -1;
    if(ebx == NULL) goto R;
    ebx->elem = dl;
    ebx->next = c;
    *l = ebx;
    a = 0;
R:
    return a;
}