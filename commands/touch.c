#include "touch.h"

void mytouch(char **args)
{
    if (strcmp(args[0],"touch")==0)
    {
        int fd = open(args[1], O_CREAT | O_WRONLY, 0644);

        if (fd == -1)
        {
            perror("open");
            return;
        }
        // update details of this file if he was exist , if not set details :
         
        if (utimensat(AT_FDCWD, args[1], NULL, 0) == -1)
        {
            perror("utimensat");
        }

        close(fd);
    }
}