/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:08:22 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/28 10:31:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_var
{
    int j;
    int i;
    int pid;
    char *file_name;
}   t_var;

void ft_herdoc(t_data *data)
{
    t_var v;

    v.i = -1;
    while (++v.i < data->cmds_len)
    {
        v.file_name = ft_get_file_name();
        v.pid = fork();
        if (v.pid == 0)
        {
            v.j = -1;
            while (data->cmds[v.i].words[++v.j])
            {
                if (data->cmds[v.i].words[v.j]->t == HERE_DOC)
                    ft_create_herdoc_file(data, v.i, v.j, v.file_name);
            }
            free(v.file_name);
            exit(0);
        }
        else
        {
            g_var.pid_herdoc = v.pid;
            wait(NULL);
            ft_update_herdoc_info(data, v.i, v.file_name);
        }
    }
}
