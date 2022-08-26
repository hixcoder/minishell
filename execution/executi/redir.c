/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:45:43 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/25 23:42:43 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_redir(t_command cmds, int i, int *outfile)
{
    if (cmds.words[i]->t == REDIRECT_OUT)
        *outfile = open(cmds.words[++i]->w, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    else if (cmds.words[i]->t == REDIRECT_OUT_APND)
        *outfile = open(cmds.words[++i]->w, O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (*outfile == -1)
        ft_error("Error: open");
}

void ft_redir_in(t_command cmds, int i, int *infile)
{
    *infile = open(cmds.words[++i]->w, O_RDONLY, 0777);
    if (*infile == -1)
    {
        ft_putstr_fd("minishell: ", STDERR);
        ft_putendl_fd("No such file or directory: ", STDERR);
        ft_putstr_fd(cmds.words[i]->w, STDERR);
    }
}

void ft_trait_redir(t_data *data, int k, int *infile, int *outfile)
{
    int i;

    i = 0;
    while (data->cmds[k].words[i])
    {
        if (data->cmds[k].words[i]->t == REDIRECT_OUT || data->cmds[k].words[i]->t == REDIRECT_OUT_APND)
            ft_redir(data->cmds[k], i, outfile);
        if (data->cmds[k].words[i]->t == REDIRECT_IN)
            ft_redir_in(data->cmds[k], i, infile);
        i++;
    }
}
