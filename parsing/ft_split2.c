/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:19:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 18:34:04 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_ft_split2_vars
{
	int		row;
	int		dst_len;
	int		len;
	int		i;
	char	**dst;
}	t_split2_vars;

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
	t_split2_vars	v;

	v.dst_len = ft_rowlen(s, c);
	v.dst = (char **)malloc(sizeof(char *) * v.dst_len);
	if (v.dst == NULL)
		return (NULL);
	v.row = 0;
	v.i = -1;
	while (s[++v.i])
	{
		if (s[v.i] != c)
		{
			v.len = ft_prdctlen(&s[v.i], c);
			v.dst[v.row] = malloc(sizeof(char) * (v.len + 1));
			if (v.dst[v.row] == NULL)
				return (ft_free2(v.dst));
			ft_memcpy(v.dst[v.row], &s[v.i], sizeof(char) * v.len);
			v.dst[v.row][v.len] = '\0';
			v.row++;
			v.i += v.len - 1;
		}
	}
	v.dst[v.row] = NULL;
	return (v.dst);
}
