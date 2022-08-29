/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:54:56 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 16:19:05 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_varb
{
	char	*tmp;
	int		k;
	int		l;
	char	*exitsts;
	int		len;
	int		a;
}	t_varb;

void	ft_change_value(t_data *data, int i, int j)
{
	t_varb	varb;

	varb.k = 0;
	varb.l = 0;
	varb.exitsts = ft_itoa(g_var.exit_status);
	varb.len = ft_strlen(varb.exitsts) + ft_strlen(data->cmds[i].cmds[j]) - 2;
	varb.tmp = malloc(sizeof(char) * (varb.len + 1));
	while (data->cmds[i].cmds[j][varb.k])
	{
		varb.a = 0;
		if (data->cmds[i].cmds[j][varb.k] == '$'
			&& data->cmds[i].cmds[j][varb.k + 1] == '?' )
		{
			while (varb.exitsts[varb.a])
				varb.tmp[varb.l++] = varb.exitsts[varb.a++];
			varb.k = varb.k + 2;
		}
		else
			varb.tmp[varb.l++] = data->cmds[i].cmds[j][varb.k++];
	}
	varb.tmp[varb.l] = '\0';
	free(data->cmds[i].cmds[j]);
	free(varb.exitsts);
	data->cmds[i].cmds[j] = varb.tmp;
}

int	ft_isexitdollar(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
			return (1);
		i++;
	}
	return (0);
}

void	ft_fixdollar(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->cmds_len)
	{
		j = 0;
		while (data->cmds[i].cmds[j])
		{
			if (ft_isexitdollar(data->cmds[i].cmds[j]))
				ft_change_value(data, i, j);
			j++;
		}
		i++;
	}
}
