/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_appen_utile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:02:37 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 09:05:25 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_append(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_add_char(char *src, char c)
{
	int		lent_src;
	char	*result;
	int		i;

	result = 0;
	lent_src = ft_strlen(src);
	result = (char *)ft_calloc(lent_src + 2, sizeof(char));
	i = 0;
	while (i < lent_src)
	{
		result[i] = src[i];
		i++;
	}
	if (src)
		free(src);
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}
