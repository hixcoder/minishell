/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:31:07 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 18:17:06 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_param
{
	char	*res;
	int		res_len;
	int		old_w_len;
	int		new_w_len;
	char	*s;
	char	*old_w;
	char	*new_w;
}	t_param;

void	ft_make_new_string(t_param *param, int from)
{
	int	i;
	int	j;
	int	lock;

	i = 0;
	j = 0;
	lock = 0;
	while (j < param->res_len)
	{
		if (i >= from && lock == 0 && ft_memcmp(ft_strnstr(&param->s[i], \
		param->old_w, ft_strlen(&param->s[i])), &param->s[i], \
		param->old_w_len) == 0)
		{
			ft_memcpy(&param->res[j], param->new_w, param->new_w_len);
			j += param->new_w_len;
			i += param->old_w_len - 1;
			lock = 1;
		}
		else
			param->res[j++] = param->s[i];
		i++;
	}
	param->res[j] = '\0';
}

// Given three strings ‘s’, ‘old_w’ and ‘new_w’. 
// The task is find all occurrences of the word ‘old_w’ in 
// string ‘s’ and replace them with word ‘new_w’.
// the 'all' tells the function if you want to change all 
// old_w occurrences to new_w or just the first occurrence 
char	*ft_strreplace(char *s, char *old_w, char *new_w, int from)
{
	int		i;
	t_param	param;

	i = (int) ft_strlen(s);
	param.s = s;
	param.old_w = old_w;
	param.new_w = new_w;
	param.old_w_len = ft_strlen(old_w);
	param.new_w_len = ft_strlen(new_w);
	param.res_len = i + param.new_w_len - param.old_w_len + 1;
	param.res = malloc(sizeof(char) * param.res_len);
	if (!param.res)
		return (NULL);
	ft_make_new_string(&param, from);
	return (param.res);
}
