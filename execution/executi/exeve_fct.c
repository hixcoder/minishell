/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:56:59 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/27 11:25:16 by ahammam          ###   ########.fr       */
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

char *ft_cmd_clear(char *str)
{
    if (str && str[0] == '.' && str[1] == '/')
        return (str + 2);
    else
        return (NULL);
}

char *ft_get_bin(t_data *data, int k)
{
    char **bin;
    char *path;
    char *pwd;
    char *cmd;
    int i;

    i = 0;
    path = NULL;
    pwd = ft_get_value(data, "PATH");
    bin = ft_split(pwd, ':');
    while (bin[i] && path == NULL)
        path = check_dir(bin[i++], data->cmds[k].cmds[0]);
    if (path != NULL)
        return (path);
    pwd = ft_get_value(data, "PWD");
    cmd = ft_cmd_clear(data->cmds[k].cmds[0]);
    if (cmd == NULL)
        return (NULL);
    path = check_dir(pwd, cmd);
    printf("path=%s\n", path);
    if (path != NULL)
        return (path);
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