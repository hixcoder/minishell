/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:31:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/28 18:18:50 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void get_exit_status(int status)
{

    if (WIFEXITED(status))
        g_var.exit_status = WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
    {
        g_var.exit_status = WTERMSIG(status);
        if (g_var.exit_status == 2) // ctrl+c
            g_var.exit_status = 130;
        if (g_var.exit_status == 3) // ctrl+/
        {
            write(1, "Quit: 3\n", 10);
            g_var.exit_status = 131;
        }
    }
}

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
    else if (sig == SIGINT && g_var.pid_child == 0 && g_var.pid_herdoc == 0)
    {
        ft_putstr_fd("\n", 2);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        g_var.exit_status = 1;
    }
    if (sig == SIGQUIT && !g_var.pid_child) //  !g_var.is_in_child
    {
        printf("💰\033[0;92m Minishell 💰 \033[0;91m━> \033[0m");
        g_var.exit_status = 130;
    }
}
