/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:49:19 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/25 11:03:50 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;
	char	uc;

	i = 0;
	uc = (char) c;
	ps = (char *) s;
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

// this function returns the index of 'c' in string 's', and if it's not exist return -1
int	ft_strchr2(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}