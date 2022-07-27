/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:27:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/27 13:01:33 by hboumahd         ###   ########.fr       */
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

int ft_is_singl_qoted(char *s)
{
    int i;
    char end_qote;
    
    i = -1;
    while (s[++i])
    {
        if (s[i] == '\'' || s[i] == '\"')
            end_qote = s[i];
    }
    if (end_qote == '\'' == 1)
        return (1);
    return (0);
}

// this check if there is an env var(start with '$') and expand it
// sInd : is the space index
void    ft_expand_env_vars(char *s)
{
    int i;
    int sInd;

    i = -1;
    sInd = 0;
    while (s[++i])
    {
        if (s[i] == '$' && ft_is_singl_qoted(&s[i+1]) == 0)
        {
            printf("%s ==> single quoted\n", s);
            printf("%s ==> $ index is %d \n", &s[i], i);
            // now you should know the exact name of the env var (alphamum type) then do this:
            // 1- splite with $
            // 2- give the env var its value (use strstr to search in the env)
            // 3- join the strings and return them in one string
        }
    }
}
// hello $d hh $d ==> 
/*
d=55
hello
d hh 
d
*/
void ft_expand(t_data *data, int i, int j)
{
    int     k;
    int     l;
	int     quots_nbr;
    char    *s;
    char    *tmp;
    int     len;

    quots_nbr = ft_isquoted(data->cmds[i].atr[j]);
	printf("data->cmds[%d].atr[%d] = %s   quotes nbr = %d\n",i,j, data->cmds[i].atr[j],quots_nbr);
	if (quots_nbr == 0)
		return ;
    
    // you don't have to remove all quotes just the external quotes!
    k = -1;
    l = -1;
    ft_expand_env_vars(data->cmds[i].atr[j]);
    s =  data->cmds[i].atr[j];
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