#include <stdlib.h>
#include "e2.h"
int list_equal(const node_t *l1, const node_t *l2){
    const node_t *edx = l1;
    const node_t *ecx = l2;
    int a;
L:
    a = edx == NULL || ecx == NULL;
    if(a)
        goto F;
    if(edx->elem != ecx-> elem)
        goto R;
    edx = edx->next;
    ecx = ecx->next;
    goto L;
F:
    a = (edx == NULL && ecx == NULL);
R:
    return a;
}