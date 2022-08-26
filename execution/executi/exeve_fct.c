/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:56:59 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/26 08:50:01 by ahammam          ###   ########.fr       */
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

char *ft_get_bin(t_data *data, int k)
{
    char **bin;
    t_list *temp;
    char *path;
    int i;

    temp = data->env_2;
    i = 0;
    path = NULL;
    while (temp && temp->content && ft_strncmp(temp->content, "PATH=", 5) != 0)
        temp = temp->next;
    if (!temp || !temp->content)
        return (NULL);
    bin = ft_split(temp->content + 5, ':');
    while (bin[i] && path == NULL)
        path = check_dir(bin[i++], data->cmds[k].cmds[0]);
    if (path != NULL)
        return (path);
    return (NULL);
}

void ft_execmd_bin(t_data *data, int k)
{
    if (execve(data->cmds[k].path_bin, data->cmds[k].cmds, NULL) == -1)
    {

        exit(EXIT_FAILURE);
    }
}