/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:19:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/02 13:52:56 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_readline(t_data *data)
{
    while (1)
    {
        data->args = readline("Minishell ++> ");
        // need to check the quotes rules here

        // trim and split the args
        data->cmds = ft_split(ft_strtrim(data->args, " "), '|');
        printf("args : %s\n", data->args);
        int i = -1;

        // trim the commands
        while (data->cmds[++i])
        {
            data->cmds[i] = ft_strtrim(data->cmds[i], " ");
            printf("cmds[%d] : %s\n", i, data->cmds[i]);
        }
        
        if (ft_strlen(data->args) > 0)
            add_history(data->args);
    }
}