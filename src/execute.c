#include "execut.h"


  
int execute(char **args)
{   
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return (0);

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return (-1);
    }

    /* Child process */
    if (pid == 0)
    {
        // we put here myls : 
        if (strcmp(args[0], "ls") == 0)
           {
              myls(args);
           }
             else{
                
        char path[256];
        strcpy(path,find_path(args));
        handle_redirect(args);
        execve(path,args,__environ);
        /* Only executed if execvp() fails */
        perror(args[0]);
        exit(EXIT_FAILURE);
    }}

    /* Parent process */
    waitpid(pid, &status, 0);

    return (0);
}