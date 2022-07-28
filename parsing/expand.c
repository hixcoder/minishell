/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:27:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/28 11:46:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* this check if the string is quoted 
   if yes , it returns the number of quotes
   if no , returns 0
*/
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

void ft_expand(t_data *data, int i, int j)
{
    int     k;
    int     l;
	int     quots_nbr;
    char    *s;
    char    *tmp;
    int     len;

    quots_nbr = ft_isquoted(data->cmds[i].atr[j]);
    ft_expand_env_vars(data->cmds[i].atr[j], data->env);
    s =  data->cmds[i].atr[j];
	printf("data->cmds[%d].atr[%d] = %s   quotes nbr = %d\n",i,j, data->cmds[i].atr[j],quots_nbr);
	if (quots_nbr == 0)
		return ;
    
    // you don't have to remove all quotes just the external quotes!
    k = -1;
    l = -1;
    len = ft_strlen(s) - quots_nbr;
    tmp = (char *) malloc(sizeof(char) * len);
    while (s[++k])
    {
        if (s[k] != '\"' && s[k] != '\'')
            tmp[++l] = s[k]; 
    }
    tmp[l+1] = '\0';
    printf("tmp == %s\n",tmp);
    data->cmds[i].atr[j] = tmp;
    free(tmp);
    tmp = NULL;
}