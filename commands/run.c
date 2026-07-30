#include "run.h"
int run_process(char *args[]){

if (strncmp(args[0],"./",2)==0){

    int status;    pid_t pid =fork();
    if (pid==0){

        execvp(args[0], args);
        perror("error");
    }
    wait(&status);
return 1;
}else return -1;


}