/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:23:25 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 12:10:40 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* this check if the string is quoted 
   if yes , it returns the number of quotes
   if no , returns 0
*/
int	ft_get_quotes_nbr(char *s)
{
	int		i;
	int		j;
	int		lock;
	char	q;

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

void	init_remove_quotes_vars(int *i, int *j, int *k, int *lock)
{
	*i = -1;
	*j = -1;
	*k = 0;
	*lock = 0;
}

// this function remove quotes that needs to be removed
// k is the number of quotes 
char	*ft_remove_quotes(char *s, char *tmp)
{
	int		i;
	int		j;
	int		k;
	int		lock;
	char	q;

	init_remove_quotes_vars(&i, &j, &k, &lock);
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
char	*ft_expand(t_data *data, char *s)
{
	int		quots_nbr;
	char	*tmp;
	int		len;

	s = ft_expand_env_vars(s, data);
	quots_nbr = ft_get_quotes_nbr(s);
	if (quots_nbr == 0)
		return (s);
	len = ft_strlen(s) - quots_nbr;
	tmp = (char *) malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	tmp = ft_remove_quotes(s, tmp);
	return (tmp);
}

// this function expand all strings inside 
// the 2D array: data->cmds to there env values
void	ft_expander(t_data *data)
{
	int			i;
	int			j;
	t_command	*cmds;

	i = -1;
	cmds = data->cmds;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (cmds[i].words[++j])
		{
			cmds[i].words[j]->w = ft_expand(data, cmds[i].words[j]->w);
			if (data->cmds[i].words[j]->t == HERE_DOC)
				j++;
		}
	}
}
