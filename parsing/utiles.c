/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:55:15 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/31 15:07:10 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_error(char *error)
{
	printf("%s\n", error);
	exit(1);
}

int	is_insid_qots(char const *s, int j)
{
	int i;
    int q1;
    int q2;

    i = -1;
    q1 = 0;
    q2 = 0;
    while (++i < j)
    {
        if (s[i] == '\'' && q2 % 2 == 0)
            q1++;
        if (s[i] == '\"' && q1 % 2 == 0)
            q2++;
    }
    if (q1 % 2 != 0 || q2 % 2 != 0)
        return (1);
	return (0);
}

void	ft_fill_atrs(char **tmp, t_data *data, int ind)
{
	int i;

	i = 0;
	while (tmp[i])
		i++;
	data->cmds[ind].atr = malloc(sizeof(t_word *) * (i + 1));
	data->cmds[ind].atr[i] = NULL;
	i = -1;
	while (tmp[++i]){
		data->cmds[ind].atr[i] = malloc(sizeof(t_word));
		data->cmds[ind].atr[i]->w = tmp[i];
	}
}

// what this function do:
// 1- trim and split the input by '|'
// 2- trim the commands and split them by " " then fill the values of data->cmds
void	ft_spliter(t_data *data)
{
	char	**cmdsTmp;
	char	**atrTmp;
	int		i;
	
	cmdsTmp = ft_split2(ft_strtrim(data->args, " "), '|');
	i = -1;
	while (cmdsTmp[++i])
		data->cmds_len = i + 1;
	data->cmds = malloc(sizeof(t_command) * data->cmds_len);
	if (!data->cmds)
	{
		free(data->cmds);
		exit(1);
	}
	i = -1;
	while (cmdsTmp[++i])
	{
		printf("cmdsTmp[%d] : %s\n", i, cmdsTmp[i]);
		atrTmp = ft_split2(ft_strtrim(cmdsTmp[i], " "), ' ');
		ft_fill_atrs(atrTmp, data, i);
		free(atrTmp);
		free(cmdsTmp[i]);
		data->cmds[i].cmd = data->cmds[i].atr[0];
		data->cmds[i].atr = &(data->cmds[i].atr[1]);
	}
	atrTmp = NULL;
	cmdsTmp = NULL;
}

// this function expand all strings inside the 2D array: data->cmds to there env values
void	ft_expander(t_data *data)
{
	int i;
	int j;
	
	i = -1;
	while (++i < data->cmds_len)
	{
		j = -1;
		data->cmds[i].cmd->w = ft_expand(data->env, data->cmds[i].cmd->w);
		while (data->cmds[i].atr[++j])
			data->cmds[i].atr[j]->w = ft_expand(data->env, data->cmds[i].atr[j]->w);
	}
}