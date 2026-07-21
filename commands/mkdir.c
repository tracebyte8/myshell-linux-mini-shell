#include "mkdir.h"

void mymkdir(char *args[]){


    if (strcmp(args[0],"mkdir")==0){

             if (mkdir(args[1],0777)==0){
                   printf("the directory are created %s ",args[1]);
               }else{
                    perror("mkdir failed");
                }
    }

}