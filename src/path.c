#include "path.h"

/*

 * Educational implementation of the PATH search that execvp()
 * you can just use in execute.c -> execvp instead of execve .
 * because execvp is check if this command exist or not and give the path , and execve do not .
 * so i add this to check and give the real path 

*/


char *find_path(char **args){

    static char full_path[1024];

    char *env_path = getenv("PATH");

    if (env_path == NULL)
        return NULL;

    char path_copy[1024];
    strcpy(path_copy, env_path);

    char *dir = strtok(path_copy, ":");

    while (dir != NULL)
    {
        snprintf(full_path,
                 sizeof(full_path),
                 "%s/%s",
                 dir,
                 args[0]);

        if (access(full_path, X_OK) == 0)
            return full_path;

        dir = strtok(NULL, ":");
    }

    return NULL;
}