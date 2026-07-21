#include "ls.h"
#include <dirent.h>

void myls(char **args){
 


        if (strcmp(args[0],"ls") == 0  && args[1] == NULL){

             DIR *dir = opendir("."); 
             struct dirent *entity;
              
               if (dir==NULL){
                  perror("unable to open this directory . \n");
                  exit(0);
                }

            while ((entity = readdir(dir)) != NULL) {
                   printf("%s\n", entity->d_name);
                  }
            closedir(dir);
            
            }


            // case of ls -l:

            if (strcmp(args[0],"ls")==0 && strcmp(args[1],"-l")==0 ){

             DIR *dir = opendir("."); 
             struct dirent *entity;
             struct stat st;
              
               if (dir==NULL){
                  perror("unable to open this directory . \n");
                  exit(0);
                }

            while ((entity = readdir(dir)) != NULL) {
                stat(entity->d_name,&st);
                printf("%c%c%c%c%c%c%c%c%c%c ",
                  S_ISDIR(st.st_mode) ? 'd' : '-',

                  (st.st_mode & S_IRUSR) ? 'r' : '-',
                  (st.st_mode & S_IWUSR) ? 'w' : '-',
                  (st.st_mode & S_IXUSR) ? 'x' : '-',

                  (st.st_mode & S_IRGRP) ? 'r' : '-',
                  (st.st_mode & S_IWGRP) ? 'w' : '-',
                  (st.st_mode & S_IXGRP) ? 'x' : '-',
 
                  (st.st_mode & S_IROTH) ? 'r' : '-',
                  (st.st_mode & S_IWOTH) ? 'w' : '-',
                  (st.st_mode & S_IXOTH) ? 'x' : '-'
                                                     );

            printf("%8ld %s\n", st.st_size, entity->d_name);
            }
            closedir(dir);
            
            }
          }