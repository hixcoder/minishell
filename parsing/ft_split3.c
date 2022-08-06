/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:19:50 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/11 20:26:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int is_delimiter2(char const **c, char const *s)
{
	int i;
	
	i = -1;
	while (c[++i])
	{
		if (ft_memcmp(c[i], s, ft_strlen(c[i])) == 0)
			return (1);
	}
	return (0);
}

static int	ft_rowlen(char const *s, char const **c)
{
	int	j;
	int	row;

	j = 0;
	row = 1;
	while (s[j])
	{
		if (is_delimiter2(c, &s[j]) == 0 &&
			((is_delimiter2(c, &s[j + 1]) == 1 && is_insid_qots(s, j + 1) == 0) || s[j + 1] == '\0'))
			row++;
		j++;
	}
	return (row);
}

static int	ft_prdctlen(char const *s, char const **c)
{
	int	len;

	len = 0;
	while (s[len] && (is_delimiter2(c, &s[len]) == 0 || is_insid_qots(s, len) == 1))
		len++;
	return (len);
}

static char	**ft_free(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
	return (NULL);
}

static char	**ft_fillrows(char **dst, const char *s, char const **c)
{
	int	row;
	int	j;
	int	len;
	int	i;

	row = 0;
	i = 0;
	while (s[i])
	{
		if (is_delimiter2(c, &s[i]) == 0)
		{
			len = ft_prdctlen(s + i, c) + i;
			dst[row] = malloc(sizeof(char) * (len + 1 - i));
			if (dst[row] == NULL)
				return (ft_free(dst));
			j = 0;
			while (i < len)
				dst[row][j++] = s[i++];
			dst[row++][j] = '\0';
		}
		if (s[i] != '\0')
			i++;
	}
	dst[row] = NULL;
	return (dst);
}

char	**ft_split3(char const *s, char const **c)
{
	int		row;
	char	**dst;

	if (!s)
		return (NULL);
	row = ft_rowlen(s, c);
	dst = (char **)malloc(sizeof(char *) * row);
	if (dst == NULL)
		return (NULL);
	if (row == 1)
		dst[0] = NULL;
	dst = ft_fillrows(dst, s, c);
	return (dst);
}
