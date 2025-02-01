#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAXCOM 1000
#define MAXLIST 100

void init_shell(){
    clear();
    printf("shell yru");
    char* username=getenv("USER");
    printf(" %s",username);
    printf("\n");
    sleep(1);
    clear();
}

int takeInput(char* str){
    char* buf;
    buf=readline("\n>>");
    if(strlen(buf)!=0){
        add_history(buf);
        strcpy(str,buf);

    }else{
        return 1;
    }
}

// Printing the directory details.

void printDir(){
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    printf("\nDir:%s",cwd);

}


void execAgrs(char ** parsed){
    pid_t pid=fork();

    if(pid==-1){
        perror("fork");
    }else if(pid==0){
        if(execvp(parsed[0],parsed)<0){
            printf("Not execute");
        }
        exit(0);
    }else{
        wait(NULL);
        return;
    }
}