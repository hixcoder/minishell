/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 12:41:32 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

  
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
void	ft_tokenizer(t_data *data)
{
	int i;
	int j;
	
	i = -1;
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
			if (data->cmds[i].words[j]->t != ARG && data->cmds[i].words[j]->t != MY_FILE
				&& data->cmds[i].words[j + 1])
				data->cmds[i].words[j + 1]->t = MY_FILE;
		}
	}
}