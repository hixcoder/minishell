#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

    int pid;
    int fd[2];
    int f3;

    int f2 = open("test5.c", O_CREAT | O_RDWR, 0777);
    printf("f2 : %d\n", f2);
    pid = fork();
    pipe(fd);
    if (pid == 0)
    {
        close(fd[0]);
        write(f2, "Hello World", 11);
        printf("f2 : %d\n", f2);
        write(fd[1], &f2, sizeof(int));
        close(fd[1]);
        exit(0);
    }
    else
    {
        close(fd[1]);
        read(fd[0], &f3, sizeof(int));
        close(fd[0]);
        wait(NULL);
        printf("sddd : %d\n", f3);
        write(f2, "\nHello World 2", 15);
    }

    return 1;
}