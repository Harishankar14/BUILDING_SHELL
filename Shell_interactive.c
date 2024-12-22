#include "shell.h"

void shell_interactve(){
    char *line;
    char **args;    //inorder to allocate the string returned by the read_line func.
    int status=-1;

    do{
        printf("simple prompts");
        line=readline();
        args=split_line(line);
        status=exec(args);

        // we are avoiding mem leaks
        free(line);
        free(args);
        while(status>0){
            // exiting the stataus
            exit(status)
        }
        

    }while(staus==-1){
        printf("No operation required");
    }
}