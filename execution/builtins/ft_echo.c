/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:12:03 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/27 23:06:41 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_echo(t_command cmds)
{
    int i;
    int nl;

    i = 1;
    nl = 0;
    while (cmds.cmds[i] && !ft_strcmp(cmds.cmds[i], "-n"))
    {
        nl = 1;
        i++;
    }
    while (cmds.cmds[i])
    {
        if (!ft_strcmp(cmds.cmds[i], "$?"))
            printf("%d", g_var.exit_status);
        ft_putstr_fd(cmds.cmds[i], 1);
        if (cmds.cmds[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (!nl)
        write(1, "\n", 1);
    return (0);
}