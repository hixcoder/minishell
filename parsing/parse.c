/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/30 15:58:47 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	g_var.g_t = t;
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

int	setup_readline(t_data *data)
{
	signal(SIGINT, ft_signal_handler_int);
	signal(SIGQUIT, ft_signal_handler_quit);
	g_var.pid_herdoc = 0;
	g_var.is_killed = 0;
	g_var.pid_child = 0;
	g_var.malloc_error = 0;
	setup_term();
	data->args = readline(" Minishell-1.0$ ");
	if (data->args == NULL)
	{
		write(1, "\033[1A\033[16C", 10);
		write(1, "exit\n", 6);
		return (0);
	}
	if (ft_strlen(data->args) > 0)
		add_history(data->args);
	return (1);
}

void	ft_readline(t_data *data)
{
	while (setup_readline(data))
	{
		if (ft_check_syntax(data, 1) == -1 || ft_check_syntax(data, 2) == -1)
			continue ;
		if (ft_spliter(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue ;
		}
		if (ft_tokenizer(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue ;
		}
		ft_expander(data);
		if (ft_get_commands(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue ;
		}
		ft_herdoc(data);
		tcsetattr(0, TCSANOW, &g_var.g_t);
		ft_minishell(data);
		ft_free(data);
	}
}
