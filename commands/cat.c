#include "cat.h"

// you can use fopen and also fgets ..... 


void mycat(char **args){

    if (strcmp(args[0],"cat")==0){

          int fd = open(args[1],O_RDONLY);
          char buffer[1024];
          ssize_t bytes;

           if (fd==-1){
             perror("open file failed");
             return ;
            }

          bytes=read(fd,buffer,sizeof(buffer));
              while (bytes>0){
                 write(1,buffer,bytes);
                 bytes=read(fd,buffer,sizeof(buffer));
                }

          close(fd);
    }
}