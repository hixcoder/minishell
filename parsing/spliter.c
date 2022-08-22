/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:24:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 18:19:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this function takes the string s and return 1 if it contains only spaces and 0 otherways
int ft_is_space(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			return (0);
	}
	return (1);
}

void ft_fill_atrs(char **tmp, t_data *data, int ind)
{
	int i;

	i = 0;
	while (tmp[i])
		i++;
	data->cmds[ind].words = malloc(sizeof(t_word *) * (i + 1));
	data->cmds[ind].words[i] = NULL;
	i = -1;
	while (tmp[++i])
	{
		data->cmds[ind].words[i] = malloc(sizeof(t_word));
		data->cmds[ind].words[i]->w = tmp[i];
		tmp[i] = NULL;
	}
}

// what this function do:
// 1- trim and split the input by '|'
// 2- trim the commands and split them by " " then fill the values of data->cmds
int ft_spliter(t_data *data)
{
	char **cmdsTmp;
	char **atrTmp;
	int i;

	cmdsTmp = ft_split2(ft_strtrim(data->args, " "), '|');
	i = -1;
	while (cmdsTmp[++i])
	{
		if (ft_is_space(cmdsTmp[i]) == 1)
			return (-1);
	}
	data->cmds_len = i;
	data->cmds = malloc(sizeof(t_command) * data->cmds_len);
	if (!data->cmds)
		return (-1);
	i = -1;
	while (cmdsTmp[++i])
	{
		cmdsTmp[i] = ft_check_redirections(cmdsTmp[i]);
		// printf("cmdsTmp[%d] : %s\n", i, cmdsTmp[i]);
		atrTmp = ft_split2(ft_strtrim(cmdsTmp[i], " "), ' ');
		ft_fill_atrs(atrTmp, data, i);
		free(atrTmp);
		free(cmdsTmp[i]);
		if (data->cmds[i].words == NULL)
			return (-1);
	}
	atrTmp = NULL;
	cmdsTmp = NULL;
	return (0);
}
