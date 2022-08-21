/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:21:05 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/19 15:19:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_echo(t_command *cmds)
{
    int i;
    int nl;

    i = 0;
    nl = 0;
    while (cmds->atr[i] && !ft_strcmp(cmds->atr[i]->w, "-n"))
    {
        nl = 1;
        i++;
    }
    while (cmds->atr[i] && cmds->atr[i]->w)
    {
        printf("%s", cmds->atr[i]->w);
        if (cmds->atr[i + 1] && cmds->atr[i + 1]->w)
            printf(" ");

        i++;
    }
    if (!nl)
        printf("\n");
}