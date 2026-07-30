#include "myshell.h"

#define MAX_ARGS 256

int main(void)
{
    char *input;
    char *args[MAX_ARGS];

    printf("----- mini shell -----\n");

    while (1)
    {
        signal(SIGINT, signale_handler);
        print_prompt();
        input = readline("");
    
        if (input == NULL)
        {
            printf("\nexit\n");
            break;
        }

        int argc = spilt(input, args, MAX_ARGS);
        
        // Empty 
        if (args[0] == NULL)
        {
            free(input);
            continue;
        }
        history_command(args);


        int pipe_index = check_pipe(args);

        if (pipe_index != -1)
        {
            execute_pipe(args, pipe_index);
        }
        else
        {
            if(run_process(args)==1){
              continue;  
            } 
            builtin_command(args, argc);
            execute(args);
        }

        mytouch(args);
        print_history(args);
        add_history(input);
        free(input);
    }

    return 0;
}