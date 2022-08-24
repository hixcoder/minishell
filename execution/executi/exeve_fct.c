/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:56:59 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/24 16:33:09 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_execve(char *path, t_data *data, int k)
{

    if (execve(path, data->cmds[k].cmds, NULL) == -1)
    {
        ft_putstr_fd("minishell: ", STDERR);
        ft_putstr_fd(data->cmds[k].cmds[0], STDERR);
        ft_putstr_fd(": command not found\n", STDERR);
        exit(EXIT_FAILURE);
    }
}

char *check_dir(char *bin, char *command)
{
    DIR *folder;
    struct dirent *item;
    char *path;
    char *tmp;

    path = NULL;
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

void ft_execmd_bin(t_data *data, int k)
{
    char **bin;
    t_list *temp;
    char *path;
    int i;

    temp = data->env_2;
    i = 1;
    while (temp && temp->content && ft_strncmp(temp->content, "PATH=", 5) != 0)
        temp = temp->next;
    if (!temp || !temp->content)
        ft_execve(data->cmds[k].cmds[0], data, k);
    bin = ft_split(temp->content + 5, ':');
    if (!bin[0])
        return;
    path = check_dir(bin[0], data->cmds[k].cmds[0]);
    while (bin[i] && path == NULL)
        path = check_dir(bin[i++], data->cmds[k].cmds[0]);
    if (path != NULL)
        ft_execve(path, data, k);
    else
        ft_execve(data->cmds[k].cmds[0], data, k);
}