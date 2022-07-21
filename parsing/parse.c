/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/21 12:15:05 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_readline(t_data *data)
{
	char		**cmdsTmp;
	int j;
	int i;
	
	while (1)
	{
		data->args = readline("Minishell ++> ");
		if (ft_strlen(data->args) > 0)
			add_history(data->args);

		// trim and split the input by '|'
		cmdsTmp = ft_split(ft_strtrim(data->args, " "), '|');
		printf("args : %s\n", data->args);

		// trim the commands and split them by " " then fill the values of data->cmds
		i = -1;
		while (cmdsTmp[++i])
		{
			printf("cmdsTmp[%d] : %s\n", i, cmdsTmp[i]);
			data->cmds[i].atr = ft_split(ft_strtrim(cmdsTmp[i], " "), ' ');
			j = -1;
			while (data->cmds[i].atr[++j])
			{
				if (j == 0)
					data->cmds[i].cmd = data->cmds[i].atr[j];
			}
		}
		data->cmds_len = i;
		data->cmds[j].atr = &(data->cmds[j].atr[1]);

		// here I print the values of data->cmds
		j = -1;
		while (++j < i)
		{
			printf("data->cmds[%d].cmd : %s\n", j, data->cmds[j].cmd);
			int k = -1;
			while (data->cmds[j].atr[++k])
				printf("data->cmds[%d].atr[%d] : %s\n", j, k, data->cmds[j].atr[k]);
			
		}
	}
}