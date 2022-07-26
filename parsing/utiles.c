/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:55:15 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/26 12:41:34 by hboumahd         ###   ########.fr       */
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

// what this function do:
// 1- trim and split the input by '|'
// 2- trim the commands and split them by " " then fill the values of data->cmds
void	ft_spliter(t_data *data)
{
	char	**cmdsTmp;
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
		data->cmds[i].atr = ft_split2(ft_strtrim(cmdsTmp[i], " "), ' ');
		free(cmdsTmp[i]);
		data->cmds[i].cmd = data->cmds[i].atr[0];
		data->cmds[i].atr = &(data->cmds[i].atr[1]);
	}
	cmdsTmp = NULL;
}

// here we remove all quotes "" '' 
// and we replace env vars with there values
void	ft_expander(t_data *data)
{
	int i;
	int j;
	int quots_nbr;
	
	i = -1;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].atr[++j])
		{
			quots_nbr = ft_isquoted(data->cmds[i].atr[j]);
			printf("data->cmds[%d].atr[%d] = %s   quotes nbr = %d\n",i,j, data->cmds[i].atr[j],quots_nbr);
			if (quots_nbr > 0)
				ft_expand(data, i, j, quots_nbr);
		}
	}
}