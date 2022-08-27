/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:08:22 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/27 18:03:29 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// chmod numbers: 4(r) + 2(w) + 1(x)

void    ft_create_hedoc_file(t_data *data, int i, int j, int file_nbr)
{
    char *file;
    int fd;
    char *line;

    file = ft_strdup("/tmp/minishell_herdocx");
    file[21] = file_nbr + '0';
    fd = open(file, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0600);
    free(file);
    if (fd == -1)
        return ;
    write(1, "Heredoc> ", 9);
    while ((line = get_next_line(0)))
    {
        if (ft_strcmp(line, "\n") == 0)
        {
            write(1, "Heredoc> ", 9);
            continue;
        }
        if (strncmp(line, data->cmds[i].words[j + 1]->w, ft_strlen(line) - 1) != 0)
        {
            write(1, "Heredoc> ", 9);
            write(fd, line, ft_strlen(line));
        }
        else
            break;
    }
    close(fd);
}

void    ft_herdoc_hedoc_info(t_data *data, int i, int j, int file_nbr)
{
    char *file;

    file = ft_strdup("/tmp/minishell_herdocx");
    file[21] = file_nbr + '0';
    data->cmds[i].words[j]->t = REDIRECT_IN;
    free(data->cmds[i].words[j + 1]->w);
    data->cmds[i].words[j + 1]->w = file;
}

void ft_herdoc(t_data *data)
{
    int j;
    int i;
    int file_nbr;
    int pid;

    i = -1;
    file_nbr = -1;
    while (++i < data->cmds_len)
    {
        pid = fork();
        if (pid == 0)
        {
            j = -1;
            while (data->cmds[i].words[++j])
            {
                if (data->cmds[i].words[j]->t == HERE_DOC)
                    ft_create_hedoc_file(data, i, j, ++file_nbr);
            }
            exit(0);
        }
        else
        {
            data->herdoc_pid = pid;
            wait(NULL);
            j = -1;
            while (data->cmds[i].words[++j])
            {
                if (data->cmds[i].words[j]->t == HERE_DOC)
                    ft_herdoc_hedoc_info(data, i, j, ++file_nbr);
            }
        }
    }
}
