/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:28:38 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/30 15:58:21 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// // ctrl+c 2
// // ctrl+/ 3
void	get_exit_status(int status)
{
	if (WIFEXITED(status))
		g_var.exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_var.exit_status = WTERMSIG(status);
		if (g_var.exit_status == 2)
			g_var.exit_status = 130;
		if (g_var.exit_status == 3)
		{
			write(1, "Quit: 3\n", 10);
			g_var.exit_status = 131;
		}
	}
}

void	ft_signal_handler_int(int sig)
{
	if (sig == SIGINT && g_var.pid_child != 0)
	{
		kill(g_var.pid_child, SIGKILL);
		ft_putstr_fd("\n", 2);
		g_var.pid_child = 0;
		g_var.exit_status = 1;
	}
	else if (sig == SIGINT && g_var.pid_herdoc != 0)
	{
		kill(g_var.pid_herdoc, SIGKILL);
		g_var.pid_herdoc = 0;
		g_var.is_killed = 1;
		g_var.exit_status = 1;
	}
	else if (sig == SIGINT && g_var.pid_child == 0 && g_var.pid_herdoc == 0)
	{
		tcsetattr(0, TCSANOW, &g_var.g_t);
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_var.exit_status = 1;
	}
}

void	ft_signal_handler_quit(int sig)
{
	if (rl_line_buffer && ft_strlen(rl_line_buffer))
	{
		write(1, "\n", 1);
		exit(0);
	}
	if (sig == SIGQUIT && !g_var.pid_child)
	{
		printf(" Minishell-1.0$ ");
		g_var.exit_status = 130;
	}
}
