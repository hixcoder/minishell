/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:12:32 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/26 12:05:37 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int **ft_create_pipes(int nbr_pipe)
{
    int i;
    int **tab;

    tab = (int **)malloc(sizeof(int *) * (nbr_pipe + 1));
    i = 0;
    while (i < nbr_pipe)
    {
        tab[i] = (int *)malloc(sizeof(int) * 2);
        pipe(tab[i]);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

void ft_close_all_pipes(int **pipes)
{
    int i;

    i = 0;
    while (pipes[i])
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}

void ft_run_cmd(t_data *data, int k, int **pipes)
{
    int infile;
    int outfile;

    infile = 0;
    outfile = 1;
    ft_trait_redir(data, k, &infile, &outfile);
    if (infile == 0)
    {
        if (k > 0)
            dup2(pipes[k - 1][0], 0);
    }
    else
        dup2(infile, STDIN_FILENO);
    if (outfile == 1)
    {
        if (k < data->cmds_len - 1)
            dup2(pipes[k][1], 1);
    }
    else
        dup2(outfile, STDOUT_FILENO);
    ft_close_all_pipes(pipes);
    ft_execute_cmd(data, k);
}

void ft_multiple_cmds(t_data *data)
{
    int **pipes;
    int k;
    int pid;

    pipes = ft_create_pipes(data->cmds_len - 1);
    k = 0;
    while (k < data->cmds_len)
    {
        data->cmds[k].path_bin = ft_get_bin(data, k);
        if (ft_is_builtin(data->cmds[k].cmds[0]) || data->cmds[k].path_bin != NULL)
        {
            pid = fork();
            if (pid == 0)
            {
                ft_run_cmd(data, k, pipes);
                exit(EXIT_SUCCESS);
            }
        }
        else
        {
            ft_putstr_fd("minishell: ", STDERR);
            ft_putstr_fd(data->cmds[k].cmds[0], STDERR);
            ft_putstr_fd(": command not found\n", STDERR);
        }
        k++;
    }
    ft_close_all_pipes(pipes);
    waitpid(pid, NULL, 0);
    while (waitpid(-1, NULL, 0) > 0)
        ;
}