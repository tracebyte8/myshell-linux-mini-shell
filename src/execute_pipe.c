#include "handl.h"
#include "path.h"
#include "redirect.h"
int execute_pipe(char *args[],int index_pipe){
    args[index_pipe] = NULL;
    int status1,status2;
    char **left=args;
    char **right=&args[index_pipe+1];
    int fd[2];
        if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }
    pid_t pid1=fork();

    if(pid1==0){

    close(fd[0]);
    dup2(fd[1],STDOUT_FILENO);

        char path[256];
                close(fd[1]);

        strcpy(path,find_path(left));
        handle_redirect(left);
        execve(path,left,__environ);
    }

    pid_t pid2=fork();

    if (pid2==0){

    close(fd[1]);
    dup2(fd[0],STDIN_FILENO);

        char path[256];
        strcpy(path,find_path(right));
        handle_redirect(right);
                       close(fd[0]);
 
        execve(path,right,__environ);


perror(left[0]);
exit(EXIT_FAILURE);
    }
    close(fd[0]);
close(fd[1]);

waitpid(pid1, &status1, 0);
waitpid(pid2, &status2, 0);
return (0);

    
}