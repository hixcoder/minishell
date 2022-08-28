
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include <termios.h>
#include <sys/stat.h>
#include "./get_next_line/get_next_line.h"

static int ft_strlen1(const char *s1)
{
    int i;

    i = 0;
    while (s1[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s1)
{
    int i;
    char *pdst;
    int s1len;

    i = 0;
    s1len = ft_strlen1(s1);
    pdst = malloc(sizeof(char) * (s1len + 1));
    if (pdst == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        pdst[i] = s1[i];
        i++;
    }
    pdst[i] = '\0';
    return (pdst);
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int check_dir(char *file)
{
    DIR *folder;
    struct dirent *item;

    folder = opendir("/tmp");
    if (!folder)
        return (0);
    while ((item = readdir(folder)))
    {
        if (ft_strcmp(item->d_name, file) == 0)
            return (1); // found
    }
    closedir(folder);
    return (0); // not found
}

void ft_get_name_file(char *namefile)
{
    char *result;
    i++;
    result = ft_strdup(namefile);

    result[0] = ft_char1(namefile);
}

int main()
{
    char *name_file;
    name_file = malloc(sizeof(char) * 6);
    name_file = "aaaaa";
    ft_get_name_file(name_file);
}