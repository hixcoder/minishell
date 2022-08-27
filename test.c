#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int i = 0;
    while (i < 100000)
    {
        printf("Main program started\n");
        i++;
        sleep(1);
    }

    return 1;
}