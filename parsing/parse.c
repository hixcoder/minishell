
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

char    *ft_type_printer(Type t)
{
    if (t == REDIRECT_IN)
        return ("REDIRECT_IN");
    else if (t == REDIRECT_OUT)
        return ("REDIRECT_OUT");
    else if (t == HERE_DOC)
        return ("HERE_DOC");
    else if (t == REDIRECT_OUT_APND)
        return ("REDIRECT_OUT_APND");
    else
        return ("ARG");
}

// here I print the values of data->cmds
void ft_print_values(t_data *data, int st)
{
	int j;
	if (data->cmds == NULL)
		return ;
	printf("===========================\n");
	j = -1;
	while (++j < data->cmds_len)
	{
		int k;

		if (st == 1)
		{
			k = -1;
			printf("data->cmds[%d].cmd->w : %s\n", j, data->cmds[j].cmd->w);
			while (data->cmds[j].atr[++k] && st == 1)
				printf("data->cmds[%d].atr[%d]->w : %s\n", j, k, data->cmds[j].atr[k]->w);
		}
		else
		{
			k = -1;
			printf("data->cmds[%d].cmd->w : %s {%s}\n", j, data->cmds[j].cmd->w, ft_type_printer(data->cmds[j].cmd->t));
			while (data->cmds[j].atr[++k] && st == 2)
				printf("data->cmds[%d].atr[%d]->w : %s {%s}\n", j, k, data->cmds[j].atr[k]->w,ft_type_printer(data->cmds[j].atr[k]->t));
		}
		
	}
}

void    ft_readline(t_data *data)
{
	while (1)
	{
		data->args = readline("Minishell ++> ");
		if (ft_strlen(data->args) > 0)
			add_history(data->args);
		printf("args : %s\n", data->args);
		// check if quotes are closed
		if (ft_check_quotes(data->args) == 1)
		{
			printf("syntax error: unclosed quotes\n");
			continue;
		}

		// you need to split with > < >> ...
		// and tokenize before expanding
		ft_spliter(data);
		ft_print_values(data, 1);
		
		ft_expander(data);
		ft_print_values(data, 1);

		ft_tokenizer(data);
		ft_print_values(data, 2);
	}
}

