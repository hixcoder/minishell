/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/31 15:38:13 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// here I print the values of data->cmds
void ft_print_values(t_data *data)
{
	int j;
	if (data->cmds == NULL)
		return ;
	printf("===========================\n");
	j = -1;
	while (++j < data->cmds_len)
	{
		printf("data->cmds[%d].cmd : %s\n", j, data->cmds[j].cmd);
		int k = -1;
		while (data->cmds[j].atr[++k])
			printf("data->cmds[%d].atr[%d] : %s\n", j, k, data->cmds[j].atr[k]);
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
		ft_spliter(data);
		ft_print_values(data);
		
		ft_expander(data);
		ft_print_values(data);
	}
}