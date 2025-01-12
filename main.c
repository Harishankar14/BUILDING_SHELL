#include <stdio.h>
#include <cstdlib>

/*
   so here before i build something,
   i have to take care of simplicity,
   for noww i will just make a simple thing
   ALR LETS BEGIN WITH THE FAMOUS QUOTE.asm

   "LIFETIME OF A PROGRAM IS MORE THAN JUST LOOPING"

*/

int main(int argc, char **argv){

    lsh_loop();
    return EXIT_SUCCESS;
}

/*
  so major thing which i have to keep in mind is that
  1. Read... operation.
  2. Write operation
  3. Execute.

  heh..sounds simple..lol too hard.. but where there's a will there is a way 
*/

void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf(">");
        line=lsh_read_line();
        argss=lsh_split_line(line);  // command, we have to split into agr, so that, it takes one by one.
        status=lsh_execute(args);
    }while(status);   // if the staus is majorly 1. boolean would have been better.
}

/*
   Okay that was just an intro
   next is readling a line. 
   major issue is that, we can't predict, how much does the user types, 
   so we create a block first of all and then add shit, so that 
   if (memory_limit > LIMIT)-> malloc(size(ofchar)*size)
*/


#define LSH_RL_BUFSIZE 1024

char *lsh_readline(void){
    int bufsize=LSH_RL_BUFSIZE;
    int position=0;
    char *buffer=malloc(sizeof(char)*bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c=getchar();
        if(c==EOF || c=="\n"){
            buffer[position]='NULL';
            return buffer
        }else{
            buffer[position]=c;
        }
        position++;
    }

    // now important part, what if we exceed the buff size/

    if(position>bufsize){
        bufsize+=LSH_RL_BUFSIZE;
        buffer=realloc(buffer,bufsize);

        if(!buffer){
            fprintf(stderr, "lsh: allocation error\n");
            exit(EXIT_FAILURE);
        }
    }
}

