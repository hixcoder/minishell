/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:22:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 10:46:33 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_run_simple_cmd(t_data *data)
{
	int	infile;
	int	outfile;
	int	tmp[2];

	tmp[0] = dup(STDIN_FILENO);
	tmp[1] = dup(STDOUT_FILENO);
	infile = 0;
	outfile = 1;
	ft_trait_redir(data, 0, &infile, &outfile);
	if (infile != 0)
		ft_dup2_close(infile, STDIN_FILENO);
	if (outfile != 1)
		ft_dup2_close(outfile, STDOUT_FILENO);
	ft_execute_cmd(data, 0);
	ft_dup2_close(tmp[0], STDIN_FILENO);
	ft_dup2_close(tmp[1], STDOUT_FILENO);
}

void	ft_simple_cmd(t_data *data)
{
	int	pid;

	if (!ft_is_builtin(data->cmds[0].cmds[0]))
	{
		data->cmds[0].path_bin = ft_get_bin(data, 0);
		if (data->cmds[0].path_bin != NULL || data->cmds[0].words[0]->t != ARG)
		{
			pid = fork();
			if (pid == 0)
				ft_run_simple_cmd(data);
			g_var.pid_child = pid;
			waitpid(pid, &g_var.exit_status, 0);
			free(data->cmds[0].path_bin);
			get_exit_status(g_var.exit_status);
		}
		else if (!ft_cmd_is_path(data->cmds[0].cmds[0]))
		{
			ft_print_error2(data->cmds[0].cmds[0], ": command not found\n");
			g_var.exit_status = 127;
		}
	}
	else
		ft_run_simple_cmd(data);
}
