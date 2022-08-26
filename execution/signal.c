/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:31:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/26 11:57:03 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_signal_handler(int sig)
{
    if (sig == SIGINT)
    {
        ft_putstr_fd("\n", 2);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}
