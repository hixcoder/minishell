
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
				printf("data->cmds[%d].cmds[%d] : |%s| \n", j, k, data->cmds[j].cmds[k]);
		}
		printf("\n");
	}
}

<<<<<<< HEAD
// here we free the all
void ft_free(t_command *cmds, int cmds_len)
{
	int j;
	int i;

	if (cmds == NULL)
		return ;
	j = -1;
	while (++j < cmds_len)
	{
		i = -1;
		while (cmds[j].words[++i])
		{
			free(cmds[j].words[i]);
			cmds[j].words[i] = NULL;
		}
		i = -1;
		while (cmds[j].cmds[++i])
		{
			free(cmds[j].cmds[i]);
			cmds[j].cmds[i] = NULL;
		}
	}
	free(cmds);
	cmds = NULL;
}

void    ft_readline(t_data *data)
=======
void ft_readline(t_data *data)
>>>>>>> 85acab1beea9bbbe9767322e6964abf7740f8503
{
	while (1)
	{
		data->args = readline("Minishell ++> ");
		if (ft_strlen(data->args) > 0)
			add_history(data->args);
		// printf("args : %s\n", data->args);
		if (ft_check_syntax(data, 1) == -1 || ft_check_syntax(data, 2) == -1)
			continue;
		if (ft_spliter(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		// ft_print_values(data, 1);
		ft_expander(data);
		if (ft_tokenizer(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		if (ft_redirector(data) == -1)
		{
			ft_check_syntax(data, 0);
			continue;
		}
		int k = 0;
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

		ft_free(data->cmds, data->cmds_len);
	}
}
