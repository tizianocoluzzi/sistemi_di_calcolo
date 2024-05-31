//SCRIVERE LA SOLUZIONE QUI...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e1.h"

void get_cmd_line(char* argv[MAX_TOKENS]){
    char* str = malloc(1024);
    fgets(str, 1024, stdin);
    printf("%s", str);
    char* b = malloc(64);
    b = strtok(str, " \t\n");
    int i = 0;
    while(b != NULL){
        argv[i] = malloc(64);
        strcpy(argv[i], b);
        b = strtok(NULL, " \t\n");
        i++;
    }
    argv[i] = NULL;
}