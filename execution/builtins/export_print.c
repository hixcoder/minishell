/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:54:56 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 08:59:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_list	*ft_duplicat_env(t_list *env)
{
	t_list	*tmp;
	t_list	*result;
	t_list	*new;
	char	*str;

	tmp = env;
	result = NULL;
	while (tmp)
	{
		str = ft_strdup(tmp->content);
		new = ft_lstnew(str);
		ft_lstadd_back(&result, new);
		tmp = tmp->next;
	}
	return (result);
}

void	ft_sort_env(t_list *env)
{
	t_list	*tmp;
	t_list	*tmp2;
	char	*min;

	tmp = env;
	while (tmp)
	{
		tmp2 = tmp;
		min = tmp->content;
		while (tmp2)
		{
			if (ft_strcmp(tmp2->content, min) < 0)
			{
				tmp->content = tmp2->content;
				tmp2->content = min;
				min = tmp->content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	ft_body_env(char *str, int *i, char **c)
{
	while (str[*i])
	{
		printf("%c", str[*i]);
		if (str[*i] == '=')
		{
			*c = "\"";
			printf("\"");
		}
		*i = *i + 1;
	}
}

int	ft_print_env(t_list *env)
{
	t_list	*tmp;
	t_list	*tmp2;
	char	*str;
	int		i;
	char	*c;

	i = 0;
	c = "";
	tmp = ft_duplicat_env(env);
	tmp2 = tmp;
	ft_sort_env(tmp);
	while (tmp)
	{
		printf("declare -x ");
		i = 0;
		c = "";
		str = tmp->content;
		ft_body_env(str, &i, &c);
		printf("%s\n", c);
		tmp = tmp->next;
	}
	ft_lstclear(&tmp2, free);
	return (1);
}
