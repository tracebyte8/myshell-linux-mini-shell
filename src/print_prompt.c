#include "print_prompt.h"
void print_prompt(){

        char *username = getenv("USER");
        
        if (username != NULL) { 
            char prompt[2048];
            char path[256];
            getcwd(path,sizeof(path));

            snprintf(prompt, sizeof(prompt),GREEN " %s"RESET "$" BLUE"%s>" RESET, path,username);
            printf("%s", prompt);
        }}