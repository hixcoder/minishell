/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:27:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/26 12:55:23 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_isquoted(char *s)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while (s[++i])
    {
        if (s[i] == '\"' || s[i] == '\'')
            j++;
    }
    return (j);
}

void ft_expand(t_data *data, int l1, int l2, int quots_nbr)
{
    int i;
    int j;
    char    *s;
    char    *tmp;
    int     len;

    i = -1;
    j = -1;
    s = data->cmds[l1].atr[l2];
    len = ft_strlen(s) - quots_nbr;
    tmp = (char *) malloc(sizeof(char) * len);
    while (s[++i])
    {
        if (s[i] != '\"' && s[i] != '\'')
            tmp[++j] = s[i]; 
    }
    tmp[j+1] = '\0';
    printf("tmp == %s\n",tmp);
    data->cmds[l1].atr[l2] = tmp;
    free(tmp);
    tmp = NULL;
}