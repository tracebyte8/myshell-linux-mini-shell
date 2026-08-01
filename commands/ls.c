#include "ls.h"
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
void ls_normale(void){

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



void ls_l(void){
              // case of ls -l:


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
             


void ls_file(char **args){
                char file[256];
         strncpy(file, args[1], sizeof(file) - 1);
               file[sizeof(file) - 1] = '\0';    

               DIR *dir = opendir("."); 
               struct dirent *entity;
              
               if (dir==NULL){
                  perror("unable to open this directory . \n");
                  exit(0);
                }

            while ((entity = readdir(dir)) != NULL) {
              if (strcmp(entity->d_name,file)==0){
                   printf("%s\n", entity->d_name);
                   break;

                }     
            }
            closedir(dir);
            
            }
              

void ls_l_file(char **args){
                char file[256];

              // ls -l file.txt

                 strncpy(file, args[2], sizeof(file) - 1);
                 file[sizeof(file) - 1] = '\0';    
                 
                   DIR *dir = opendir("."); 
                   struct dirent *entity;
                   struct stat st;
              
               if (dir==NULL){
                  perror("unable to open this directory . \n");
                  exit(0);
                }

            while ((entity = readdir(dir)) != NULL) {
              if(strcmp(args[2],entity->d_name)==0){
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
            break;
            }}
            closedir(dir);
            

              }
             
              
void myls(char **args){
 
if(strcmp(args[0],"ls")==0 && args[1]==NULL){
  ls_normale();


     }else if (strcmp(args[1],"-l")==0 && args[2]==NULL){
     ls_l();

         }else if (strcmp(args[1],"-l")==0 && args[2]!=NULL){
          ls_l_file(args);

        }else if(strcmp(args[0],"ls")==0 && args[1]!=NULL){
          ls_file(args);
        }



              }
             
          