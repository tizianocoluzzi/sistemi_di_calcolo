#include "e1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_person(person_t*p){
    if(p == NULL || p->name == NULL || p->surname == NULL) {
        printf("ziopera null\n");
        return;
    }
    printf("%s  %s  %d  %d\n", p->name, p->surname, p->year, p->has_phd);
}

person_t * new_person(char* nome, char* cognome, int y, int phd){
    person_t * p = (person_t*) malloc(sizeof(person_t));
    p->name = malloc(64);
    p->surname = malloc(64);
    p->has_phd = phd;
    strcpy(p->name, nome);
    strcpy(p->surname,cognome);
    p->year = y;
    p->next = NULL;
    //print_person(p);
}

int parseCSV(const char* file, person_t** out, int minAge) {
    FILE* f = fopen(file, "r"); 
    person_t * pp = NULL;
    *out = NULL;
    if(!f) return -1;
    char* linea = malloc(64);
    char* nome = malloc(64);
    char* cognome = malloc(64);
    char* data = malloc(15);
    char* phd = malloc(3);
    int bphd;
    while(fgets(linea, 64, f) != NULL ){
        //printf("%s\n", linea);
        nome = strtok(linea, ",");
        cognome = strtok(NULL, ",");
        int year;
        char app[4];
        data = strtok(NULL, ",");
        sscanf(data, "%*[0-9]-%*[0-9]-%s", app);
        year = atoi(app);
        //printf("%d\n", year);
        phd = strtok(NULL, ",");
        if(phd == "yes") bphd = 1;
        else bphd = 0;
        if(year >= minAge){
            person_t* p = new_person(nome, cognome, year, bphd);
            if(*out == NULL){
                *out = p;
                pp = *out;
            }
            else{
                (*out)->next = p;
                *out = (*out)->next;
            }

        }
        //aggiungi(out, new_person(nome, cognome, year, bphd));
    }
    *out = pp;
    return 0;
}