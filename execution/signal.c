/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:31:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/28 12:25:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_signal_handler(int sig)
{
    if (sig == SIGINT && g_var.pid_child != 0)
    {
        kill(g_var.pid_child, SIGKILL);
        g_var.pid_child = 0;
        g_var.exit_status = 1;
    }
    else if (sig == SIGINT && g_var.pid_herdoc != 0)
    {
        kill(g_var.pid_herdoc, SIGKILL);
        g_var.pid_herdoc = 0;
        g_var.is_killed = 1;
        g_var.exit_status = 1;
    }
    else if (sig == SIGINT && g_var.pid_child == 0 && g_var.pid_child == 0)
    {
        ft_putstr_fd("\n", 2);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        g_var.exit_status = 1;
    }
}
