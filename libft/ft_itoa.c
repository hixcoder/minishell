/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:38:28 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/07 12:23:45 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_hndlzero(char *str, int n)
{
	if (n == 0)
		*str = '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_hndlzero(str, n);
	str[len] = '\0';
	while (n != 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			if (n == -2147483648)
			{
				str[1] = '2';
				n = -147483648;
			}
			n = -n;
		}
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
