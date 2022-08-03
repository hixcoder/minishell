/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:59:16 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/01 12:02:25 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this function sort 2d array of strings by thier lenght
// ex: s = {"qwerty", "qwertyui", "qwe"} ==> s = {"qwertyui", "qwerty", "qwe"}
void    ft_strlen_sort(char **s, int s_len)
{
    int i;
    int j;
    int t[s_len];
    int t_tmp;
    char *tmp;

    i = -1;
    while (s[++i])
        t[i] = ft_strlen(s[i]);
    i = -1;
    while(++i < s_len)
    {
        j = i;
        while (++j < s_len)
        {
            if (t[i] < t[j])
            {
                t_tmp = t[i];
                t[i] = t[j];
                t[j] = t_tmp;
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}