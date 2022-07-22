/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/22 09:18:48 by hboumahd         ###   ########.fr       */
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

		i = -1;
		while (cmdsTmp[++i])
			data->cmds_len = i + 1;
		data->cmds = malloc(sizeof(t_command) * data->cmds_len);
		if (!data->cmds)
			exit(1);
		i = -1;
		// trim the commands and split them by " " then fill the values of data->cmds
		while (cmdsTmp[++i])
		{
			printf("cmdsTmp[%d] : %s\n", i, cmdsTmp[i]);
			data->cmds[i].atr = ft_split(ft_strtrim(cmdsTmp[i], " "), ' ');
			data->cmds[i].cmd = data->cmds[i].atr[0];
			data->cmds[i].atr = &(data->cmds[i].atr[1]);
		}

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