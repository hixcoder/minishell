
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/03 13:48:37 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_type_printer(Type t)
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

void setup_term()
{
	struct termios t;
	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
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

// here we free "data->cmds"
void ft_free(t_data *data)
{
	int j;
	int i;
	t_command *cmds;

	cmds = data->cmds;
	if (cmds == NULL)
		return;
	j = -1;
	while (++j < data->cmds_len)
	{
		i = -1;
		while (cmds[j].words[++i])
		{
			free(cmds[j].words[i]->w);
			free(cmds[j].words[i]);
		}
		free(cmds[j].words);
		i = -1;
		while (cmds[j].cmds[++i])
			free(cmds[j].cmds[i]);
		free(cmds[j].cmds);
	}
	free(cmds);
}

void ft_readline(t_data *data)
{
	while (1)
	{
		signal(SIGINT, &ft_signal_handler);
		signal(SIGQUIT, &ft_signal_handler);
		setup_term();
		data->args = readline("💰 \033[0;92mMinishell 💰 \033[0;91m━> \033[0m");
		if (data->args == NULL)
		{
			ft_putstr_fd("exit\n", 2);
			break;
		}
		add_history(data->args);
		if (ft_check_syntax(data, 1) == -1 || ft_check_syntax(data, 2) == -1)
			continue;
		if (ft_spliter(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		if (ft_tokenizer(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		ft_expander(data);
		if (ft_redirector(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		ft_herdoc(data);
		// ft_print_values(data, 2);
		// ft_print_values(data, 3);
		ft_minishell(data);
		ft_free(data);
	}
}
