/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:23:25 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 12:23:28 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* this check if the string is quoted 
   if yes , it returns the number of quotes
   if no , returns 0
*/
int ft_get_quotes_nbr(char *s)
{
    int i;
    int j;
    int lock;
    char q;
    
    i = -1;
    j = 0;
    lock = 1;
    q = 'q';
    while (s[++i])
    {
        if (s[i] == q || j % 2 == 0)
            lock = 1;
        if ((s[i] == '\"' || s[i] == '\'') && lock == 1)
        {
            q = s[i];
            j++;
            lock = 0;
        }
    }
    return (j);
}

// this function remove quotes that needs to be removed
// k is the number of quotes 
char    *ft_remove_quotes(char *s, char *tmp)
{
    int i;
    int j;
    int k;
    int lock;
    char q;
    
    i = -1;
    j = -1;
    k = 0;
    lock = 0;
    q = 'q';
    while (s[++i])
    {
        if (s[i] == q || k % 2 == 0)
            lock = 0;
        if ((s[i] == '\"' || s[i] == '\'') && lock == 0)
        {
            q = s[i];
            lock = 1;
            k++;
            continue ;
        }
        tmp[++j] = s[i]; 
    }
    tmp[++j] = '\0';
    return (tmp);
}

// here we remove all quotes "" '' 
// and we replace env vars with there values
char    *ft_expand(char **env, char *s)
{
	int     quots_nbr;
    char    *tmp;
    int     len;

    s = ft_expand_env_vars(s, env);;
    quots_nbr = ft_get_quotes_nbr(s);
	if (quots_nbr == 0)
		return (s);
    len = ft_strlen(s) - quots_nbr;
    if (!(tmp = (char *) malloc(sizeof(char) * len)))
        return (NULL);
    tmp = ft_remove_quotes(s, tmp);
    return (tmp);
}

// this function expand all strings inside the 2D array: data->cmds to there env values
void	ft_expander(t_data *data)
{
	int i;
	int j;
	
	i = -1;
	while (++i < data->cmds_len)
	{
		j = -1;
		data->cmds[i].words[0]->w = ft_expand(data->env, data->cmds[i].words[0]->w);
		while (data->cmds[i].words[++j])
			data->cmds[i].words[j]->w = ft_expand(data->env, data->cmds[i].words[j]->w);
	}
}