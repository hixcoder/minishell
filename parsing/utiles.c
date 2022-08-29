/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:55:15 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 16:56:17 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(t_data *data, char *key)
{
	t_list	*tmp;
	char	*content;
	int		key_len;

	tmp = data->env_2;
	key_len = ft_strlen(key);
	while (tmp)
	{
		content = tmp->content;
		if (ft_strncmp(key, content, key_len) == 0 && content[key_len] == '=')
			return (ft_strchr(tmp->content, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}
