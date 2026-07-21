#include "redirect.h"





// this function for redierct :
// it include : 
/*

    **    STDIN   <
    **    STDOUT  >
    **    STDIN (in the end of the file) >>
    **    STDERR 2>

*/

void handle_redirect(char **args){

int i =0;
 
 for (i=0;args[i]!=NULL;i++){
  if (strcmp(args[i],">")==0){
 
       char file[256];
       strcpy(file,args[2]);
       int fd=open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
       
       if (fd<0){
           perror("error in open fd\n");
           exit(0);
                }

        if (dup2(fd, STDOUT_FILENO) == -1)
        {
             perror("dup2");
             exit(EXIT_FAILURE);
        }
        dup2(fd,STDOUT_FILENO);
        close(fd);
        args[1]=NULL;
    }
    


    // to the end of file :
    // we can do it without the lseek (system call) , just use append the text will be add in the end of file .
    // with lseek we do thie manualy , jump to 0 byte to end of file  

    else if(strcmp(args[i],">>")==0){
        char file [256];
               strcpy(file,args[2]);

               int fd=open(file, O_WRONLY | O_CREAT , 0644);
               
               lseek(fd,0,SEEK_END);

               if (fd<0){
                   perror("error in open fd\n");
                   exit(0);
                }
                
                if (dup2(fd, STDOUT_FILENO) == -1)
                {
                   perror("dup2");
                   exit(EXIT_FAILURE);
                  }
                close(fd);
                args[1]=NULL;

    }



    // now we give the input to the command .
    // just read file and and change to stdin .

        else if(strcmp(args[i],"<")==0){
            char file [256];
               strcpy(file,args[2]);

               int fd=open(file, O_RDONLY, 0644);
               
               if (fd<0){
                   perror("error in open fd\n");
                   exit(0);
                }
                
                if (dup2(fd, STDIN_FILENO) == -1)
                {
                   perror("dup2");
                   exit(EXIT_FAILURE);
                  }
                close(fd);
                args[1]=NULL;


        }


        // now this for redierct error :

        else if(strcmp(args[i],"2>")==0 ){
            char file [256];
               strcpy(file,args[2]);

                int fd=open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
               
               if (fd<0){
                   perror("error in open fd\n");
                   exit(0);
                }
                
                if (dup2(fd, STDERR_FILENO) == -1)
                {
                   perror("dup2");
                   exit(EXIT_FAILURE);
                  }
                close(fd);
                args[1]=NULL;


        }

}}