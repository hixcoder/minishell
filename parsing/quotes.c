/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:14:45 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/02 13:32:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int    ft_quotes_handler(char *s)
{
    int i;
    
    i = -1;
    while(s[++i])
    {
        if (s[i] == q)
            return (i);
    }
    return (-1);
}

int    ft_quotes_checker(char q, char *start)
{
    int i;
    
    i = -1;
    while(start[++i])
    {
        if (start[i] == q)
            return (i);
    }
    return (-1);
}