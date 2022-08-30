/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:45:43 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/30 17:18:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_redir(t_command cmds, int i, int *outfile)
{
	char	*file;

	file = cmds.words[i + 1]->w;
	if (cmds.words[i]->t == REDIRECT_OUT)
		*outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmds.words[i]->t == REDIRECT_OUT_APND)
		*outfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
}

void	ft_redir_in(t_command cmds, int i, int *infile)
{
	*infile = open(cmds.words[++i]->w, O_RDONLY, 0644);
	if (*infile == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putendl_fd("No such file or directory: ", STDERR);
		ft_putstr_fd(cmds.words[i]->w, STDERR);
		exit(EXIT_FAILURE);
	}
}

void	ft_trait_redir(t_data *data, int k, int *infile, int *outfile)
{
	int	i;

	i = 0;
	while (data->cmds[k].words[i])
	{
		if (data->cmds[k].words[i]->t == REDIRECT_OUT
			|| data->cmds[k].words[i]->t == REDIRECT_OUT_APND)
			ft_redir(data->cmds[k], i, outfile);
		if (data->cmds[k].words[i]->t == REDIRECT_IN)
			ft_redir_in(data->cmds[k], i, infile);
		i++;
	}
}
