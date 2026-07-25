#include <stdio.h>
#include "history.h"


void history_command(char **args){
if (args[0]!=NULL){
FILE *file=fopen("history.txt","a");
    int i =0;

while (args[i]!=NULL){
    fprintf(file," %s ",args[i]);
    i++;

}
fprintf(file,"\n");
    fclose(file);
}
}
void print_history(char *args[]){
 
    if (strcmp(args[0],"history")==0){
   FILE *file=fopen("history.txt","r");
   char buffer[256];

    // Read line-by-line until fgets returns NULL (end of file)
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); 
        printf("\n");
    }
    fclose(file);
printf("history");
}

}
