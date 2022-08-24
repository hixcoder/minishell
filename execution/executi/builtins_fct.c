/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:12:22 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/23 18:12:58 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
int ft_is_builtin(char *cmd)
{
    if (ft_strcmp(cmd, "echo") == 0)
        return (1);
    if (ft_strcmp(cmd, "pwd") == 0)
        return (1);
    if (ft_strcmp(cmd, "cd") == 0)
        return (1);
    if (ft_strcmp(cmd, "env") == 0)
        return (1);
    if (ft_strcmp(cmd, "export") == 0)
        return (1);
    if (ft_strcmp(cmd, "unset") == 0)
        return (1);
    return (0);
}

void ft_execmd_built(t_data *data, int k)
{
    if (ft_strcmp(data->cmds[k].cmds[0], "echo") == 0)
        ft_echo((data->cmds)[k]);
    if (ft_strcmp(data->cmds[k].cmds[0], "pwd") == 0)
        ft_pwd();
    if (ft_strcmp(data->cmds[k].cmds[0], "cd") == 0)
        ft_cd(data, k);
    if (ft_strcmp(data->cmds[k].cmds[0], "env") == 0)
        ft_env(data, k);
    if (ft_strcmp(data->cmds[k].cmds[0], "export") == 0)
        ft_export(data, k);
    if (ft_strcmp(data->cmds[k].cmds[0], "unset") == 0)
        ft_unset(data, k);
}