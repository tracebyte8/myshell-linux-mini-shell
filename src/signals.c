#include "signals.h"
#include "print_prompt.h"

void signale_handler(int sig){
 
   if (sig == SIGINT){
      printf("\n");
   print_prompt();
    signal(SIGINT,signale_handler);
 }



}