/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:31:07 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/29 12:37:38 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_get_old_w_nbr(char *s, char *old_w, int old_w_len, int *i)
{
    int old_w_nbr;
    int j;

    old_w_nbr = 0;
    j = -1;
    while (s[++j])
    {
        if (ft_memcmp(ft_strnstr(&s[j], old_w, ft_strlen(&s[j])), &s[j], sizeof(char)) == 0)
        {
            old_w_nbr++;
            j += old_w_len - 1;
        }
    }
    *i = j;
    return (old_w_nbr);
}

// this is a good resource : https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
// Given three strings ‘str’, ‘old_w’ and ‘new_w’. 
// The task is find all occurrences of the word ‘old_w’ and replace them with word ‘new_w’.
char    *ft_strreplace(char *s, char *old_w, char *new_w)
{
    int i;
    int j;
    char *res;
    int  res_len;
    int old_w_len;
    int new_w_len;
    int old_w_nbr;

    new_w = ft_strdup("hix");
    
    i = -1;
    old_w_len = ft_strlen(old_w);
    new_w_len = ft_strlen(new_w);
    old_w_nbr = ft_get_old_w_nbr(s, old_w, old_w_len, &i);
    // here we make new string
    res_len = i + old_w_nbr * (new_w_len - old_w_len - 1) + 1;
    printf("old_w_nbr = %d\n", old_w_nbr);
    printf("res_len = %d\n", res_len);
    
    res = malloc(sizeof(char) * res_len);
    if (!res)
        return(NULL);
    i = -1;
    j = -1;
    while (s[++i])
    {
        if (ft_memcmp(ft_strnstr(&s[i], old_w, ft_strlen(&s[i])), &s[i], sizeof(char)) == 0)
        {
            ft_memcpy(&res[j], new_w, new_w_len * sizeof(char));
            j += new_w_len;
            i += old_w_len;
        }
        else
            res[++j] = s[i];
    }
    res[j] = '\0';
    return (res);
}


