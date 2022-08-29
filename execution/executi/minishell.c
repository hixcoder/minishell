/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:21:45 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 18:32:44 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_execute_cmd(t_data *data, int k)
{
	if (ft_is_builtin(data->cmds[k].cmds[0]))
		ft_execmd_built(data, k);
	else
		ft_execmd_bin(data, k);
}

void	ft_minishell(t_data *data)
{
	ft_fixdollar(data);
	if (data->cmds_len == 1)
		ft_simple_cmd(data);
	else if (data->cmds_len > 1)
		ft_multiple_cmds(data);
}
