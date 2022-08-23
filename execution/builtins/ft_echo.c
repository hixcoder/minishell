/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:12:03 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/22 11:10:23 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_echo(t_command cmds)
{

    int i;
    int nl;

    i = 1;
    nl = 0;
    if (cmds.cmds[i] && !ft_strcmp(cmds.cmds[i], "-n"))
    {
        nl = 1;
        i++;
    }
    while (cmds.cmds[i])
    {
        printf("%s", cmds.cmds[i]);
        if (cmds.cmds[i + 1])
            printf(" ");
        i++;
    }
    if (!nl)
        printf("\n");
}