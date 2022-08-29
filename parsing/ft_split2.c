/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:19:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 18:00:44 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_rowlen(char const *s, char c)
{
	int	j;
	int	row;

	j = 0;
	row = 1;
	while (s[j])
	{
		if (s[j] != c
			&& ((s[j + 1] == c && is_insid_qots(s, j + 1) == 0)
				|| s[j + 1] == '\0'))
			row++;
		j++;
	}
	return (row);
}

static int	ft_prdctlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c || is_insid_qots(s, i) == 1))
		i++;
	return (i);
}

static char	**ft_free2(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
	return (NULL);
}

char	**ft_split2(char const *s, char c)
{
	int		row;
	int		dst_len;
	int		len;
	int		i;
	char	**dst;

	if (!s)
		return (NULL);
	dst_len = ft_rowlen(s, c);
	// printf("dstlen = %d\n\n", dst_len);
	dst = (char **)malloc(sizeof(char *) * dst_len);
	if (dst == NULL)
		return (NULL);
	row = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_prdctlen(&s[i], c);
			dst[row] = malloc(sizeof(char) * (len + 1));
			if (dst[row] == NULL)
				return (ft_free2(dst));
			ft_memcpy(dst[row], &s[i], sizeof(char) * len);
			dst[row][len] = '\0';
			// printf("dst[%d] = %s\nlen = %d\n-----------\n", row, dst[row], len);
			row++;
			i += len - 1;
		}
	}
	dst[row] = NULL;
	// printf("\n");
	return (dst);
}
