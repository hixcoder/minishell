/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:56:59 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/27 18:35:00 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *check_dir(char *bin, char *command)
{
    DIR *folder;
    struct dirent *item;
    char *path;
    char *tmp;

    path = NULL;
    if (bin == NULL)
        return (NULL);
    folder = opendir(bin);
    if (!folder)
        return (NULL);
    while ((item = readdir(folder)))
    {
        if (ft_strcmp(item->d_name, command) == 0)
        {
            tmp = ft_strjoin(bin, "/");
            path = ft_strjoin(tmp, command);
            free(tmp);
        }
    }
    closedir(folder);
    return (path);
}

char *ft_return_sta(char *str)
{

    struct stat inf;

    if (lstat(str, &inf) == -1)
        ft_print_error2(str, ": no such file or directory\n");
    else if (S_ISDIR(inf.st_mode)) // S_IFDIR & inf.st_mode
        ft_print_error2(str, ": is a directory\n");
    else if (!(S_IXOTH & inf.st_mode))                  // || !(S_ISUID & inf.st_mode)
        ft_print_error2(str, ": permission denied \n"); //
    if (S_ISREG(inf.st_mode))
        return (ft_strdup(str));
    return (NULL);
}

char *ft_get_bin(t_data *data, int k)
{
    char **bin;
    char *path;
    char *pwd;
    int i;

    i = 0;
    path = NULL;
    pwd = ft_get_value(data, "PATH");
    bin = ft_split(pwd, ':');
    while (bin[i] && path == NULL)
        path = check_dir(bin[i++], data->cmds[k].cmds[0]);
    if (path != NULL)
        return (path);
    if (ft_cmd_is_path(data->cmds[k].cmds[0]))
        return (ft_return_sta(data->cmds[k].cmds[0]));
    return (NULL);
}

char **ft_env_list(t_data *data)
{
    char **result;
    t_list *tmp;
    int i;

    tmp = data->env_2;
    i = 0;
    result = (char **)malloc(sizeof(char *) * (ft_lstsize(tmp) + 1));
    while (tmp)
    {
        result[i] = ft_strdup(tmp->content);
        tmp = tmp->next;
        i++;
    }
    result[i] = NULL;
    return (result);
}

void ft_execmd_bin(t_data *data, int k)
{
    char **arg;

    arg = ft_env_list(data);

    if (execve(data->cmds[k].path_bin, data->cmds[k].cmds, arg) == -1)
        exit(EXIT_FAILURE);
}