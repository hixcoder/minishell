/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:33:04 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/24 19:22:36 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_isnumber(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_exit(t_data *data, int k)
{
    t_command cmd;

    cmd = data->cmds[k];
    if (cmd.cmds[1] && ft_isnumber(cmd.cmds[1]) == 0)
    {
        data->exit_status = 1;
        printf("exit\n");
        printf("minishell: exit: %s: numeric argument required\n", cmd.cmds[1]);
        exit(1);
    }
    else if (cmd.cmds[1] && ft_isnumber(cmd.cmds[1]) == 1 && cmd.cmds[2])
        printf("minishell: exit: too many arguments\n");
    else
    {
        data->exit_status = 1;
        printf("exit\n");
    }

    return (1);
}