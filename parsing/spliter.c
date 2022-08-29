/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:24:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 16:30:10 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this function takes the string s and 
// return 1 if it contains only spaces and 0 otherways
int	ft_is_space(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			return (0);
	}
	return (1);
}

void	ft_fill_atrs(char **atr_tmp, t_data *data, int ind)
{
	int	i;

	i = 0;
	while (atr_tmp[i])
		i++;
	data->cmds[ind].words = malloc(sizeof(t_word *) * (i + 1));
	data->cmds[ind].words[i] = NULL;
	i = -1;
	while (atr_tmp[++i])
	{
		data->cmds[ind].words[i] = malloc(sizeof(t_word));
		data->cmds[ind].words[i]->w = atr_tmp[i];
		// free(atr_tmp[i]);
	}
	free(atr_tmp);
}

int	ft_free_spliter(char **cmds_tmp)
{
	int	i;

	i = -1;
	while (cmds_tmp[++i])
		free(cmds_tmp[i]);
	free(cmds_tmp);
	return (-1);
}

int	ft_init_spliter_vars(t_data *data, char	**cmds_tmp)
{
	int	i;

	i = -1;
	while (cmds_tmp[++i])
	{
		if (ft_is_space(cmds_tmp[i]) == 1)
			return (ft_free_spliter(cmds_tmp));
	}
	data->cmds_len = i;
	data->cmds = malloc(sizeof(t_command) * data->cmds_len);
	if (!data->cmds)
		return (ft_free_spliter(cmds_tmp));
	return (0);
}

// what this function do:
// 1- trim and split the input by '|'
// 2- trim the commands and split them by " " then fill the values of data->cmds
int	ft_spliter(t_data *data)
{
	char	**cmds_tmp;
	char	**atr_tmp;
	char	*cmds_tmp2;
	char	*args2;
	int		i;

	args2 = ft_strtrim(data->args, " ");
	cmds_tmp = ft_split2(args2, '|');
	free(args2);
	if (ft_init_spliter_vars(data, cmds_tmp) == -1)
		return (-1);
	i = -1;
	while (cmds_tmp[++i])
	{
		// printf("cmds_tmp[%d] = %s\n", i, cmds_tmp[i]);
		cmds_tmp[i] = ft_check_redirections(cmds_tmp[i]);
		cmds_tmp2 = ft_strtrim(cmds_tmp[i], " ");
		atr_tmp = ft_split2(cmds_tmp2, ' ');
		free(cmds_tmp2);
		ft_fill_atrs(atr_tmp, data, i);
		free(cmds_tmp[i]);
		if (data->cmds[i].words == NULL)
			return (-1);
	}
	free(cmds_tmp);
	return (0);
}
