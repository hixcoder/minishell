/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:31:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/25 18:16:35 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_signal_int_handler(int sig)
{
    // if (sig == SIGINT)
    (void)sig;
    // rl_on_new_line();
    // rl_replace_line("", 0);
    // rl_redisplay();
    ft_putstr_fd("\nMinishell ++> ", 2);
}