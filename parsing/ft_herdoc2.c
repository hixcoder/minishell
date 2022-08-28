

#include "../minishell.h"

int check_dir_2(char *file)
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

char *ft_get_name_file_2()
{
    int i = 0;
    char *name = ft_itoa(i);
    while (check_dir_2(name))
    {
        free(name);
        i++;
        name = ft_itoa(i);
    }
    return (name);
}

void ft_create_hedoc_file_2(t_data *data, int i, int j, char *name_file)
{
    char *path_file;
    int fd;
    char *line;

    path_file = ft_strjoin("/tmp/", name_file);
    fd = open(path_file, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0600);
    free(path_file);
    if (fd == -1)
        return;
    write(1, "Heredoc> ", 9);
    while ((line = get_next_line(0)))
    {
        if (ft_strcmp(line, "\n") == 0)
        {
            write(1, "Heredoc> ", 9);
            write(fd, line, ft_strlen(line));
            continue;
        }
        if (strncmp(line, data->cmds[i].words[j + 1]->w, ft_strlen(line) - 1) != 0)
        {
            write(1, "Heredoc> ", 9);
            write(fd, line, ft_strlen(line));
        }
        else
            break;
    }
    close(fd);
}

void ft_herdoc_hedoc_info_2(t_data *data, int i, int j, char *path_file)
{
    char *file;

    file = ft_strjoin("/tmp/", path_file);
    data->cmds[i].words[j]->t = REDIRECT_IN;
    free(data->cmds[i].words[j + 1]->w);
    data->cmds[i].words[j + 1]->w = file;
}

void ft_herdoc_2(t_data *data)
{
    int j;
    int i;
    int pid;
    char *name_file;

    i = -1;

    while (++i < data->cmds_len)
    {
        name_file = ft_get_name_file_2();
        pid = fork();
        if (pid == 0)
        {
            j = -1;
            while (data->cmds[i].words[++j])
            {
                if (data->cmds[i].words[j]->t == HERE_DOC)
                    ft_create_hedoc_file_2(data, i, j, name_file);
            }
            exit(0);
            free(name_file);
        }
        data->herdoc_pid = pid;
        wait(NULL);
        j = -1;
        while (data->cmds[i].words[++j])
        {
            if (data->cmds[i].words[j]->t == HERE_DOC)
                ft_herdoc_hedoc_info_2(data, i, j, name_file);
        }
        free(name_file);
    }
}
