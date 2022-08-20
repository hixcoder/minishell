/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 21:23:25 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this function take the string w and return 1 if it's a redirection or 0 if it's not.
int	ft_is_redi(char *w)
{
	if (ft_memcmp(w, "<", ft_strlen("<")) == 0 || 
		ft_memcmp(w, ">", ft_strlen(">")) == 0 ||
		ft_memcmp(w, "<<", ft_strlen("<<")) == 0 ||
		ft_memcmp(w, ">>", ft_strlen(">>")) == 0)
		return (1);
	else
		return (0);
}
  
// the ft_tokenize takes the 'word' string and return its type
Type    ft_tokenize(char *word)
{
    if (ft_memcmp(word, "<", ft_strlen("<")) == 0)
        return (REDIRECT_IN);
    else if (ft_memcmp(word, ">", ft_strlen(">")) == 0)
        return (REDIRECT_OUT);
    else if (ft_memcmp(word, "<<", ft_strlen("<<")) == 0)
        return (HERE_DOC);
    else if (ft_memcmp(word, ">>", ft_strlen(">>")) == 0)
        return (REDIRECT_OUT_APND);
    else
        return (ARG);
}

// this function gives the type of each cmd and words
int	ft_tokenizer(t_data *data)
{
	int i;
	int j;
	int redi_nbr;
	
	i = -1;
	redi_nbr = 0;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].words[++j])
			data->cmds[i].words[j]->t = ft_tokenize(data->cmds[i].words[j]->w);
	}
	i = -1;
	while (++i < data->cmds_len)
	{
		j = -1;
		while (data->cmds[i].words[++j])
		{
			if (ft_is_redi(data->cmds[i].words[j]->w) == 1)
			{
				if (data->cmds[i].words[j + 1] && ft_is_redi(data->cmds[i].words[j + 1]->w ) == 0)
				{
					data->cmds[i].words[j + 1]->t = MY_FILE;
					redi_nbr--;
				}
				redi_nbr++;
			}
		}
		if (redi_nbr > 0)
			return (-1);
	}
	return (0);
}