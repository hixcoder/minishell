#include <stdio.h>
#include <limits.h>

int main()
{

#ifdef PATH_MAX
    printf("PATH_MAX is defined as %d.\n", PATH_MAX);
#else
    printf("PATH_MAX isn't defined on this system.\n");
#endif /* PATH_MAX */

    return (0);
}