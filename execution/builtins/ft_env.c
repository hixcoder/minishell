/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:11:44 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 15:59:56 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_char_instring(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_env(t_data *data, int k)
{
	t_list	*tmp;

	tmp = data->env_2;
	if (data->cmds[k].cmds[1])
	{
		printf("env: %s: No such file or directory\n", data->cmds[k].cmds[1]);
		g_var.exit_status = 127;
		return (1);
	}
	g_var.exit_status = 0;
	while (!(data->cmds[k].cmds[1]) && tmp)
	{
		if (ft_is_char_instring(tmp->content, '='))
			printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
