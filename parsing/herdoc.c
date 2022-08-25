/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:08:22 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/25 22:37:26 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#define fD_OUT 1
#define fD_IN  0

// 4(r) + 2(w) + 1(x)

void ft_herdoc(t_data *data, int i)
{
    int fd;
    int save_fd_out;

    fd = open("/tmp/herdoc", O_RDONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return ;
    save_fd_out = dup(fD_OUT);
    data->cmds[i].fd_herdoc = dup2(0, fd);
    close(fd);
        
    
    
}

