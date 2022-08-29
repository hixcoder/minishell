/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:12:22 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 10:30:43 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_builtin(char *cmd)
{
	int	a;

	if (!cmd)
		return (0);
	a = 0;
	if (ft_strcmp(cmd, "echo") == 0)
		a = 1;
	if (ft_strcmp(cmd, "pwd") == 0)
		a = 1;
	if (ft_strcmp(cmd, "cd") == 0)
		a = 1;
	if (ft_strcmp(cmd, "env") == 0)
		a = 1;
	if (ft_strcmp(cmd, "export") == 0)
		a = 1;
	if (ft_strcmp(cmd, "unset") == 0)
		a = 1;
	if (ft_strcmp(cmd, "exit") == 0)
		a = 1;
	return (a);
}

void	ft_execmd_built(t_data *data, int k)
{
	if (!ft_strcmp(data->cmds[k].cmds[0], "echo"))
		ft_echo((data->cmds)[k]);
	if (!ft_strcmp(data->cmds[k].cmds[0], "pwd"))
		ft_pwd();
	if (!ft_strcmp(data->cmds[k].cmds[0], "cd"))
		ft_cd(data, k);
	if (!ft_strcmp(data->cmds[k].cmds[0], "env"))
		ft_env(data, k);
	if (!ft_strcmp(data->cmds[k].cmds[0], "export"))
		ft_export(data, k);
	if (!ft_strcmp(data->cmds[k].cmds[0], "unset"))
		ft_unset(data, k);
	if (!ft_strcmp(data->cmds[k].cmds[0], "exit"))
		ft_exit(data, k);
}
