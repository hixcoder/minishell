/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:30:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 12:22:31 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_commands(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->cmds_len)
	{
		data->cmds[i].cmds = malloc(sizeof(char *));
		if (!data->cmds[i].cmds)
			return (-1);
		data->cmds[i].cmds[0] = NULL;
		j = -1;
		while (data->cmds[i].words[++j])
		{
			if (data->cmds[i].words[j]->t == ARG
				&& ft_strlen(data->cmds[i].words[j]->w) != 0)
				data->cmds[i].cmds = ft_add_string(data->cmds[i].cmds, \
				data->cmds[i].words[j]->w);
			else if (data->cmds[i].words[j]->t != ARG
				&& data->cmds[i].words[j]->t != MY_FILE
				&& ft_strlen(data->cmds[i].words[j + 1]->w) == 0)
				return (-1);
		}
	}
	return (0);
}
