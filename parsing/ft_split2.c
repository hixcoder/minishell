/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:19:50 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/11 20:26:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_insid_qots(char const *s, int j)
{
	int i;
    int q1;
    int q2;

    i = -1;
    q1 = 0;
    q2 = 0;
    while (++i < j)
    {
        if (s[i] == '\'' && q2 % 2 == 0)
            q1++;
        if (s[i] == '\"' && q1 % 2 == 0)
            q2++;
    }
    if (q1 % 2 != 0 || q2 % 2 != 0)
        return (1);
	return (0);
}

static int	ft_rowlen(char const *s, char c)
{
	int	j;
	int	row;

	j = 0;
	row = 1;
	while (s[j])
	{
		if (s[j] != c &&
			((s[j + 1] == c && is_insid_qots(s, j + 1) == 0) || s[j + 1] == '\0'))
			row++;
		j++;
	}
	return (row);
}

static int	ft_prdctlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && (s[len] != c || is_insid_qots(s, len) == 1))
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

static char	**ft_fillrows(char **dst, const char *s, char c)
{
	int	row;
	int	j;
	int	len;
	int	i;

	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
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

char	**ft_split2(char const *s, char c)
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
