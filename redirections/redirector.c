/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:30:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 13:05:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_redirect(t_data *data, int i, int j)
{
    if (data->cmds[i].words[j]->t == REDIRECT_IN)
        return ("REDIRECT_IN");
    else if (data->cmds[i].words[j]->t == REDIRECT_OUT)
        return ("REDIRECT_OUT");
    else if (data->cmds[i].words[j]->t == HERE_DOC)
        return ("HERE_DOC");
    else if (data->cmds[i].words[j]->t == REDIRECT_OUT_APND)
        return ("REDIRECT_OUT_APND");
}

void	ft_redirector(t_data *data)
{
    int i;
    int j;
    int redi_nbr;

    i = -1;
    redi_nbr = 0;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].words[++j])
        {
            if (data->cmds[i].words[j]->t != ARG)
            {
                redi_nbr = 1;
                ft_redirect(data, i, j);
                i++;
            }
            else
            {
                data->cmds[i].cmds = ft_add_string(data->cmds[i].cmds, data->cmds[i].words[j]->w);
            }
        }
	}
    
    
}