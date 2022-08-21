/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:38:52 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 13:50:29 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_protect(char **tmp, char *varname)
{
    if (tmp == NULL)
    {
        if (!(tmp = malloc(sizeof(char *) * 2)))
            return (NULL);
        tmp[0] = ft_strdup(varname);
        tmp[1] = NULL;
        return (tmp);
    }
    if (varname == NULL)
        return (tmp);
    return (NULL);
}

// this function you give it a 2D array and a string, 
// its job is to add the string to the 2D array 
char    **ft_add_string(char **tmp, char *varname)
{
    int     i;
    int     tmplen;
    char    **new_tmp;

    if (tmp== NULL || varname == NULL)
        return (ft_protect(tmp, varname));
    tmplen = 0;
    printf("======> %s\n", tmp[0]);
    while(tmp[tmplen])
        tmplen++;
    if (!(new_tmp = malloc (sizeof(char *) * (tmplen + 2))))
        return (NULL);
    i = -1;
    while(tmp[++i])
        new_tmp[i] = ft_strdup(tmp[i]);
    new_tmp[tmplen] = ft_strdup(varname);
    new_tmp[tmplen + 1] = NULL;
    return (new_tmp);
}