/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:31:07 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/29 16:50:40 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_param
{
	char	*res;
	int		res_len;
	int		old_w_len;
	int		new_w_len;
	int		old_w_nbr;
	char	*s;
	char	*old_w;
	char	*new_w;
}	t_param;

int	ft_get_old_w_nbr(char *s, char *old_w, int old_w_len, int *i)
{
	int	old_w_nbr;
	int	j;

	old_w_nbr = 0;
	j = -1;
	while (s[++j])
	{
		if (ft_memcmp(ft_strnstr(&s[j], old_w, \
		ft_strlen(&s[j])), &s[j], sizeof(char)) == 0)
		{
			old_w_nbr++;
			j += old_w_len - 1;
		}
	}
	*i = j;
	return (old_w_nbr);
}

void	ft_make_new_string(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < param->res_len)
	{
		if (ft_memcmp(ft_strnstr(&param->s[i], param->old_w, ft_strlen(&param->s[i])), &param->s[i], param->old_w_len) == 0)
		{
			ft_memcpy(&param->res[j], param->new_w, param->new_w_len);
			j += param->new_w_len;
			i += param->old_w_len - 1;
		}
		else
		{
			param->res[j] = param->s[i];
			j++;
		}
		i++;
	}
	param->res[j] = '\0';
}

// Given three strings ‘s’, ‘old_w’ and ‘new_w’. 
// The task is find all occurrences of the word ‘old_w’ in 
// string ‘s’ and replace them with word ‘new_w’.
char	*ft_strreplace(char *s, char *old_w, char *new_w)
{
	int		i;
	t_param	param;

	i = -1;
	param.s = s;
	param.old_w = old_w;
	param.new_w = new_w;
	param.old_w_len = ft_strlen(old_w);
	param.new_w_len = ft_strlen(new_w);
	param.old_w_nbr = ft_get_old_w_nbr(s, old_w, param.old_w_len, &i);
	param.res_len = i + param.old_w_nbr * \
	(param.new_w_len - param.old_w_len) + 1;
	param.res = malloc(sizeof(char) * param.res_len);
	if (!param.res)
		return (NULL);
	ft_make_new_string(&param);
	return (param.res);
}
