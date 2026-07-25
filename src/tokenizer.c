#include "tokeninzer.h"
#define spc " "

int check_pipe(char *args[]){
int i =0;
while (args[i]!=NULL){
if (strcmp(args[i],"|")==0){
    return i;
}
i++;
}
return -1;
}

int spilt(char *line, char *args[],int max_args){
   
    //It stores the address of the current word.
    char *token=strtok(line,spc);
    int i=0;

    while (token !=NULL && i<( max_args-1 )){
    args[i++]=token;
    token = strtok(NULL,spc);
    }
    args [i]=NULL;
    return i;

}

