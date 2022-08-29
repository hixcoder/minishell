/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 16:57:35 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_type_printer(Type t)
{
	if (t == REDIRECT_IN)
		return ("REDIRECT_IN");
	else if (t == REDIRECT_OUT)
		return ("REDIRECT_OUT");
	else if (t == HERE_DOC)
		return ("HERE_DOC");
	else if (t == REDIRECT_OUT_APND)
		return ("REDIRECT_OUT_APND");
	else if (t == MY_FILE)
		return ("MY_FILE");
	else
		return ("ARG");
}

// here I print the values of data->cmds
void ft_print_values(t_data *data, int st)
{
	int j;
	if (data->cmds == NULL)
		return;
	j = -1;
	while (++j < data->cmds_len)
	{
		int k;
		k = -1;

		if (st == 1)
		{
			while (data->cmds[j].words[++k])
				printf("data->cmds[%d].words[%d]->w : %s\n", j, k, data->cmds[j].words[k]->w);
		}
		else if (st == 2)
		{
			while (data->cmds[j].words[++k])
				printf("data->cmds[%d].words[%d]->w : %s {%s}\n", j, k, data->cmds[j].words[k]->w, ft_type_printer(data->cmds[j].words[k]->t));
		}
		else if (st == 3)
		{
			while (data->cmds[j].cmds[++k])
				printf("data->cmds[%d].cmds[%d] : %s \n", j, k, data->cmds[j].cmds[k]);
		}
		printf("\n");
	}
}

void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
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
	data->args = readline("💰\033[0;92m Minishell 💰 \033[0;91m━> \033[0m");
	if (data->args == NULL)
	{
		write(1, "\033[1A\033[20C", 10);
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
		ft_fixdollar(data);
		// ft_print_values(data, 2);
		// ft_print_values(data, 3);
		if (!g_var.is_killed)
			ft_minishell(data);
		// ft_free(data);
	}
}
