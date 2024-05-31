#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "e2.h"
void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time){
    struct booking* app;
    *list = NULL;
    struct booking* p;
    for(int i = 0; i < size; i+=37){
        int j = 0;
        char c[2];
        char* surname = malloc(30);
        char* app2 = surname;
        strncat(surname, &data[i+j],30);
        while(*surname != '_'){
            ++surname;
        }
        *surname = '\0';
        surname = app2;
        j = 30;
        char pla[2] = "";
        strncat(pla, &data[i+j],2);
        char o[5];
        j = 32;
        strncat(pla, &data[i+j],5);
        char* b = malloc(5); 
        b = strncpy(b, time, 5);
        int ora = atoi(strtok(o, ":"));
        int min = atoi(strtok(NULL,":"));
        //printf("%d %d\n", ora, min);
        int ora_t = atoi(strtok(b, ":"));
        int min_t = atoi(strtok(NULL,":"));
        //printf("%s\n%s%s\n", surname, time, pla);
        if(ora >= ora_t){
            //printf("minimio\n");
            if(ora == ora_t && min < min_t) {}
            else{
                p = (struct booking*) malloc(sizeof(struct booking));
                p->surname = malloc(30);
                p->time = malloc(5);
                p->surname = surname;
                p->places = atoi(pla);
                p->time = o;
                p->next = NULL;
                if(*list == NULL) {
                    *list = p;
                    //printf("%s\n", p->surname);
                }
                else{
                    app->next = p;
                }
                app = p;
            }
        }

        //printf("%s\n", &(data[i]));
    }
    return;
    
}
