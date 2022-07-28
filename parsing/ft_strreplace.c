/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:31:07 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/28 13:07:30 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this is a good resource : https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
// Given three strings ‘str’, ‘old_w’ and ‘new_w’. 
// The task is find all occurrences of the word ‘old_w’ and replace them with word ‘new_w’.
char    *ft_strreplace(char *s, char *old_w, char *new_w)
{
    int i;
    char *res;
    int  res_len;
    int old_w_nbr;
    int old_w_len;
    int new_w_len;
    
    i = -1;
    old_w_nbr = 0;
    old_w_len = ft_strlen(old_w);
    new_w_len = ft_strlen(new_w);
    // here count how mutch old_w we have in s
    while (s[++i])
    {
        if (ft_strnstr(&s[i], old_w, old_w_len) == &s[i])
            old_w_nbr++;
        i += old_w_len - 1;
    }

    // here we make new string
    res_len = i + old_w_nbr * (new_w_len - old_w_len) + 1;
    res = malloc(sizeof(char) * res_len);
    i = -1;
    while (s[++i])
    {
        if (ft_strnstr(&s[i], old_w, old_w_len) == &s[i])
        {
            ft_memcpy(res, new_w, res_len);
            i += new_w_len;
        }
        else
            res[i] = s[i];
    }
    res[i] = '\0';
    return (res);
}