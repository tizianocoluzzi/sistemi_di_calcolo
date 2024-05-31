// Scrivi la soluzione qui...
#include"e1.h"
#include <string.h>
int compare(const void *p1, const void *p2){
    if(strcmp(((person_t*) p1)->name, ((person_t*)p2)->name )>0) return 1;
    return 0;
}

void sort_people(person_t p[], size_t nel){
    qsort(p, nel, 8, compare);
}
person_t *find_person(char *key, person_t sorted[], size_t nel){
    int i = 0;
    for( ; i < nel; i++){
        if(strcmp(sorted[i].name, key) == 0){
            return &(sorted[i]);
        }
    }
    return NULL;
}