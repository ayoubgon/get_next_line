#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <stdio.h>


int main()
{
    int fd;
    int fd2;
    int i = 0;
    char *line;
    // char *line2;


    fd = open("test.text", O_RDONLY);
    fd2 = open("test1.text", O_RDONLY);
    
        line = get_next_line(fd);
        printf ("%d --> %s\n",fd,line);
        free (line);
        line = get_next_line(fd2);
        printf ("%d --> %s\n",fd,line);
        free (line);

        line = get_next_line(fd);
        printf ("%d --> %s\n",fd,line);
        free (line);
        line = get_next_line(fd2);
        printf ("%d --> %s\n",fd,line);
        free (line);
        
        line = get_next_line(fd);
        printf ("%d --> %s",fd,line);
        free (line);
        line = get_next_line(fd2);
        printf ("%d --> %s",fd,line);
        free (line);
        
        // printf ("%d --> %s\n",fd,line);
        // printf ("%d --> %s\n",fd2,line2);
        // free (line);
        // free(line2);

        // printf ("%d --> %s\n",fd,line);
        // printf ("%d --> %s\n",fd2,line2);
        // free (line);
        // free(line2);
    // // fd =;
    // while (i < 3)
    // {
    //     printf ("%d --> %s\n",fd,line);
    //     printf ("%d --> %s\n",fd2,line2);
    //     free (line);
    //     free(line2);
    //     i++;
    // }
    // printf ("%d --> %s",i+,line);
    // free (line);
    return 0;
}