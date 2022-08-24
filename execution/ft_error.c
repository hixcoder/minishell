/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:51:47 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/24 18:14:13 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void *minishell_perror(int err_type)
{

    if (err_type == MEM)
        ft_putstr_fd("minishell: Error malloc\n", 2);
    if (err_type == FORKERR)
        ft_putstr_fd("minishell: Error creating prosses\n", 2);
    return (NULL);
}