#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buffer[510];
    int n;
 // cat << tr << yy
    int fd = open("tr.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);

    while ((n = read(0, buffer, sizeof buffer)) > 0)
    {

        write(fd, buffer, n);

    }

    return EXIT_SUCCESS;
}