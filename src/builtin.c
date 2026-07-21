#include "builtin.h"
#include <limits.h>


// if user write exit : 
void exit_commnd(char *args[]){
if (strcmp(args[0],"exit")== 0){
    printf("bye !/n");
    exit(0);

}
}

// change directory command :
void cd_commnd(char *args[]){
 
if (strcmp(args[0],"cd")== 0){
   if (chdir(args[1])==0){
    printf ("change directory sucess %s",args[1]);
   }else {
    perror("cd failed");
   }

}
}
// current path :
void pwd_commnd(char *args[]){
    if (strcmp(args[0],"pwd")== 0){
       char path[_PC_PATH_MAX];
       if (getcwd(path,sizeof(path))!=NULL){
           printf("path -> %s",path);
       }
    }
}

// print in screnn :
void echo_commnd(char *args[],int argc){
        if (strcmp(args[0],"echo")== 0){
            for (int i = 1; i <argc; i++) {
             printf("%s", args[i]);
        
              if (i < argc - 1) {
                printf(" ");
              }
           } 
        }

}
