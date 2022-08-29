/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:46:44 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 09:07:23 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_identifier(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '_' && ft_isalpha(str[0]) != 1)
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+' && str[i + 1] == '=')
			;
		else if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_lenstring(t_list *env)
{
	t_list	*tmp;
	int		nbr;

	tmp = env;
	nbr = 0;
	while (tmp)
	{
		nbr = nbr + ft_strlen(tmp->content) + 1;
		tmp = tmp->next;
	}
	return (nbr);
}

char	*env_to_string(t_list *env)
{
	char	*result;
	t_list	*tmp;

	tmp = env;
	result = (char *)malloc(sizeof(char) * ft_lenstring(env) + 1);
	if (result == NULL)
		return (ft_error_mallocation(),NULL);
	while (tmp)
	{
		result = ft_strcat(result, (char *)tmp->content);
		tmp = tmp->next;
	}
	return (result);
}

int	ft_strncmp_env(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s2[i] != '=' && s1[i] != '=')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s2[i] == '=' && s1[i] == '=') || (s2[i] == '=' && s1[i] == '\0'))
		return (0);
	if ((s1[i] == '=' && s2[i] == '\0') || (s1[i] == '=' && s2[i] == '='))
		return (0);
	return (s1[i] - s2[i]);
}

int	ft_is_exist_env(t_list *env, const char *var)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp_env(tmp->content, var) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
