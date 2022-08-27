/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:22:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/27 17:25:33 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void ft_run_simple_cmd(t_data *data)
{
    int infile;
    int outfile;

    infile = 0;
    outfile = 1;
    ft_trait_redir(data, 0, &infile, &outfile);
    if (infile != 0)
        dup2(infile, STDIN_FILENO);
    if (outfile != 1)
        dup2(outfile, STDOUT_FILENO);
    ft_execute_cmd(data, 0);
}

int ft_simple_cmd(t_data *data)
{
    int pid;

    if (!ft_is_builtin(data->cmds[0].cmds[0]))
    {
        data->cmds[0].path_bin = ft_get_bin(data, 0);

        if (data->cmds[0].path_bin != NULL)
        {
            pid = fork();
            if (pid == -1)
                return (minishell_perror(FORKERR), 0);
            if (pid == 0)
            {
                ft_run_simple_cmd(data);
                exit(EXIT_SUCCESS);
            }
            else
            {
                g_var.pid_child = pid;
                waitpid(pid, NULL, 0);
                g_var.pid_child = 0;
            }
        }
        else if (!ft_cmd_is_path(data->cmds[0].cmds[0]))
            ft_print_error2(data->cmds[0].cmds[0], ": command not found\n");
    }
    else
        ft_run_simple_cmd(data);
    return (1);
}