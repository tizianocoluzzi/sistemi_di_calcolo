//SCRIVI LA SOLUZIONE QUI...

#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void get_cmd_line(char* argv[11]){
    char* str = malloc(1024);
    fgets(str, 1024, stdin);
    //printf("%s", str);
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

int do_shell(const char* prompt){
    int status;
    while(1){
        printf("%s", prompt);
        char* s[11];
        get_cmd_line(s);
        if(s[0] == NULL) continue;
        if(strcmp(s[0],"quit") == 0) {printf("quittato\n"); break;}
        int i = 0;
        int pid = fork();
        if(pid == 0){
            int res = execvp(s[0], s);
            if(res == -1){
                perror("comando non trovato");
                return EXIT_FAILURE;
            }
            else return EXIT_SUCCESS;
        }
        else{
            wait(&status);
        }
        
    }
}
