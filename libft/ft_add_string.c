/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:38:52 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 16:41:36 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// this function you give it a 2D array 's' and a string 'w', 
// its job is to add the string 'w' to the 2D array 's'
char    **ft_add_string(char **s, char *w)
{
    int     i;
    int     tmplen;
    char    **new_tmp;

    if (w == NULL)
        return (s);
    tmplen = 0;
    while(s[tmplen])
        tmplen++;
    if (!(new_tmp = malloc (sizeof(char *) * (tmplen + 2))))
        return (NULL);
    i = -1;
    while(s[++i])
        new_tmp[i] = ft_strdup(s[i]);
    new_tmp[tmplen] = ft_strdup(w);
    new_tmp[tmplen + 1] = NULL;
    return (new_tmp);
}