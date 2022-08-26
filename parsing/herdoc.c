/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:08:22 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/26 12:58:49 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// chmod numbers: 4(r) + 2(w) + 1(x)

void    ft_create_hedoc_file(t_data *data, int i, int j, int file_nbr)
{
    char *file;
    int     fd;
    char *line;

    file = ft_strdup("minishell_herdocx");
    file[16] = file_nbr + '0';
    fd = open(file, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0600);
    if (fd == -1)
        return ;
    while((line =  get_next_line(0)))
    {
        if (strncmp(line, data->cmds[i].words[j + 1]->w, ft_strlen(line) - 1) != 0)
            write(fd, line, ft_strlen(line));
        else
            break ;
    }
    data->cmds[i].words[j]->t = REDIRECT_IN;
    free(data->cmds[i].words[j + 1]->w);
    data->cmds[i].words[j + 1]->w = file;
    close(fd);
}

void ft_herdoc(t_data *data)
{
    int j;
    int i;
    int file_nbr;

	if (data->cmds == NULL)
		return ;
	i = -1;
    file_nbr = -1;
    
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].words[++j])
        {
            if (data->cmds[i].words[j]->t == HERE_DOC)
                ft_create_hedoc_file(data, i, j, ++file_nbr);
        }
	}
}
