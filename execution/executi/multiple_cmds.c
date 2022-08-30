/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:12:32 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/30 12:04:00 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_dup2_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	ft_run_cmd(t_data *data, int k, int **pipes)
{
	int	infile;
	int	outfile;

	infile = 0;
	outfile = 1;
	ft_trait_redir(data, k, &infile, &outfile);
	if (infile == 0)
	{
		if (k > 0)
			dup2(pipes[k - 1][0], STDIN_FILENO);
	}
	else
		ft_dup2_close(infile, STDIN_FILENO);
	if (outfile == 1)
	{
		if (k < data->cmds_len - 1)
			dup2(pipes[k][1], STDOUT_FILENO);
	}
	else
		ft_dup2_close(outfile, STDOUT_FILENO);
	ft_close_all_pipes(pipes);
	ft_free_pipes(pipes);
	ft_execute_cmd(data, k);
}

void	ft_body_multiple_cmds(t_data *data, int k, int **pipes, int *pid)
{
	data->cmds[k].path_bin = ft_get_bin(data, k);
	if (ft_is_builtin(data->cmds[k].cmds[0])
		|| data->cmds[k].path_bin != NULL
		|| data->cmds[k].words[0]->t != ARG)
	{
		*pid = fork();
		if (*pid == 0)
		{
			ft_run_cmd(data, k, pipes);
			exit(EXIT_SUCCESS);
		}
		free(data->cmds[k].path_bin);
	}
	else if (data->cmds[0].cmds[0] != NULL
		&& !ft_cmd_is_path(data->cmds[k].cmds[0]))
	{
		ft_print_error2(data->cmds[k].cmds[0], ": command not found\n");
		g_var.exit_status = 127;
	}
}

void	ft_multiple_cmds(t_data *data)
{
	int	**pipes;
	int	k;
	int	pid;

	pipes = ft_create_pipes(data->cmds_len - 1);
	k = 0;
	while (k < data->cmds_len && g_var.malloc_error == 0)
	{
		ft_body_multiple_cmds(data, k, pipes, &pid);
		k++;
	}
	g_var.pid_child = pid;
	ft_close_all_pipes(pipes);
	waitpid(pid, &g_var.exit_status, 0);
	get_exit_status(g_var.exit_status);
	while (waitpid(-1, NULL, 0) > 0)
		;
	g_var.pid_child = 0;
	ft_free_pipes(pipes);
}
