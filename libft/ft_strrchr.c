/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:16:03 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/11 08:52:17 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (ps[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i--;
	}
	return (NULL);
}
