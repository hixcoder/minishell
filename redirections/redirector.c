/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:30:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 21:27:14 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void    ft_redirect(t_data *data, int i, int j)
// {
//     if (data->cmds[i].words[j]->t == REDIRECT_IN)
//         return ("REDIRECT_IN");
//     else if (data->cmds[i].words[j]->t == REDIRECT_OUT)
//         return ("REDIRECT_OUT");
//     else if (data->cmds[i].words[j]->t == HERE_DOC)
//         return ("HERE_DOC");
//     else if (data->cmds[i].words[j]->t == REDIRECT_OUT_APND)
//         return ("REDIRECT_OUT_APND");
// }

int	ft_redirector(t_data *data)
{
    int i;
    int j;

    i = -1;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].words[++j])
        {
            if (data->cmds[i].words[j]->t != ARG)
            {
                // ft_redirect(data, i, j);
                j++;
                printf("==> test : %s\n", data->cmds[i].words[j]->w);
            }
            if (data->cmds[i].words[j]->t == ARG)
                data->cmds[i].cmds = ft_add_string(data->cmds[i].cmds, data->cmds[i].words[j]->w);
        }
	}
    return (0);
}