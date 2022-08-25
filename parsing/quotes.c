/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:14:45 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/25 10:45:05 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check if quotes are closed or not
int    ft_check_quotes(char *s)
{
    int i;
    int q1;
    int q2;

    i = -1;
    q1 = 0;
    q2 = 0;
    while (s[++i])
    {
        if (s[i] == '\'' && q2 % 2 == 0)
            q1++;
        if (s[i] == '\"' && q1 % 2 == 0)
            q2++;
    }
    if (q1 % 2 != 0 || q2 % 2 != 0)
        return (1);
    return (0);
}

int	is_insid_qots(char const *s, int j)
{
	int i;
    int q1;
    int q2;

    i = -1;
    q1 = 0;
    q2 = 0;
    while (++i < j)
    {
        if (s[i] == '\'' && q2 % 2 == 0)
            q1++;
        if (s[i] == '\"' && q1 % 2 == 0)
            q2++;
    }
    if(q1 % 2 != 0 || q2 % 2 != 0)
    {
        
        return (1);
    }
	return (0);
}
