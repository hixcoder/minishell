/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:15:02 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/28 23:24:50 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// here we free "data->cmds"
void	ft_free(t_data *data)
{
	int			j;
	int			i;
	t_command	*cmds;

	cmds = data->cmds;
	if (cmds == NULL)
		return ;
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
