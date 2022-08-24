/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:12:22 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/24 18:50:56 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
static char *ft_to_lowercase(char *str)
{
    int i;
    char *result;

    i = 0;
    if ((result = malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
        return (minishell_perror(MEM));
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            result[i] = str[i] + 32;
        else
            result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

int ft_is_builtin(char *cmd)
{
    char *lower_cmd;
    int a;

    lower_cmd = ft_to_lowercase(cmd);
    a = 0;
    if (ft_strcmp(lower_cmd, "echo") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "pwd") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "cd") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "env") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "export") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "unset") == 0)
        a = 1;
    if (ft_strcmp(lower_cmd, "exit") == 0)
        a = 1;
    free(lower_cmd);
    return (a);
}

void ft_execmd_built(t_data *data, int k)
{
    char *lower_cmd;

    lower_cmd = ft_to_lowercase(data->cmds[k].cmds[0]);
    if (!ft_strcmp(lower_cmd, "echo"))
        ft_echo((data->cmds)[k]);
    if (!ft_strcmp(lower_cmd, "pwd"))
        ft_pwd();
    if (!ft_strcmp(lower_cmd, "cd"))
        ft_cd(data, k);
    if (!ft_strcmp(lower_cmd, "env"))
        ft_env(data, k);
    if (!ft_strcmp(lower_cmd, "export"))
        ft_export(data, k);
    if (!ft_strcmp(lower_cmd, "unset"))
        ft_unset(data, k);
    if (!ft_strcmp(lower_cmd, "exit"))
        ft_exit(data, k);
    free(lower_cmd);
}