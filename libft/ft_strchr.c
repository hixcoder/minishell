/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:49:19 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/20 17:55:44 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;
	char *ps;
	char uc;

	i = 0;
	uc = (char)c;
	ps = (char *)s;
	while (ps[i] != '\0')
	{
		if (ps[i] == uc)
			return (&ps[i]);
		i++;
	}
	if (uc == '\0' && ps[i] == uc)
		return (&ps[i]);
	return (0);
}

int ft_strchrnbr(const char *s, int c)
{
	int i;
	char *ps;
	char uc;

	i = 0;
	uc = (char)c;
	ps = (char *)s;
	while (ps[i] != '\0')
	{
		if (ps[i] == uc)
			return (i);
		i++;
	}
	return (1);
}
