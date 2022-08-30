/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:50:33 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/30 11:01:43 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	**ft_create_pipes(int nbr_pipe)
{
	int	i;
	int	**tab;

	tab = (int **)malloc(sizeof(int *) * (nbr_pipe + 1));
	if (tab == NULL)
		return (ft_error_mallocation(), tab);
	i = 0;
	while (i < nbr_pipe)
	{
		tab[i] = (int *)malloc(sizeof(int) * 2);
		if (tab[i] == NULL)
			return (ft_error_mallocation(), NULL);
		pipe(tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_close_all_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	ft_error_mallocation(void)
{
	ft_putstr_fd("minishell: Error malloc", 2);
	g_var.exit_status = 139;
	g_var.malloc_error = 1;
}
