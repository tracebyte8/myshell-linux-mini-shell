


#include "myshell.h"

#define spc " "
#define MAX_ARGS 256





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




int main() {

    char *input;
    // create array of token :    Issues   Pull requests 100% Commits
    char *args[MAX_ARGS];

    printf(" ----- mini shell -----\n");

    while (1) {


        char *username = getenv("USER");
        
        if (username != NULL) {

            char prompt[2048];
            char path[256];
            getcwd(path,sizeof(path));

            snprintf(prompt, sizeof(prompt),GREEN " %s"RESET "$" BLUE"%s>" RESET, path,username);
        


         // Read a line 

        input = readline(prompt);

        // argc number of argumemts  
        int argc = spilt(input,args,MAX_ARGS);
        printf("Found %d arguments\n", argc);
        
        // case of user enter espace :
        if (args[0]==NULL)continue;
        
        // search which commands :
        execute(args);
        exit_commnd(args);
        cd_commnd(args);
        pwd_commnd(args);
        echo_commnd(args,MAX_ARGS);
        mytouch(args);
        

        // print tokens :
        for (int i = 0; i < argc; i++) {
        printf("args[%d] = %s\n", i, args[i]);

        }

        // Check for EOF (e.g., Ctrl+D) or memory allocation failure
        if (strlen (input) == 0) {
            printf("\n exit.\n");
            break;
        }
            else{
              add_history(input);
        
              free(input);
                }                
                  }
                
                
                
                
                }
             return 0;
    }
