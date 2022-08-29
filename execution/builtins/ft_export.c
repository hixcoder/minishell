/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:32:20 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 16:00:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strchr_env(const char *s, int c)
{
	int		i;
	char	*ps;
	char	uc;

	i = 0;
	uc = (char)c;
	ps = (char *)s;
	while (ps[i] != '\0')
	{
		if (ps[i] == uc)
			return (i + 1);
		i++;
	}
	return (i + 1);
}

int	ft_is_char_exist(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	update_env(t_list *env, char *par)
{
	t_list	*tmp;
	size_t	len1;
	size_t	len2;
	char	*tmp2;

	tmp = env;
	len1 = ft_is_char_exist(par, '=');
	while (tmp)
	{
		if (ft_strncmp_env(tmp->content, par) == 0)
		{
			tmp2 = (char *)(tmp->content);
			len2 = ft_is_char_exist(tmp->content, '=');
			if (len1 == ft_strlen(par) && (tmp2[len2] != '\0'))
				tmp->content = ft_strjoin(par, "=");
			else
				tmp->content = ft_strdup(par);
			free(tmp2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_add_to_env(t_list *env, char *str)
{
	t_list	*new;
	char	*tmp;

	if (ft_is_append(str))
		return (ft_append(env, str));
	else if (ft_is_exist_env(env, str))
		return (update_env(env, str));
	else
	{
		tmp = ft_strdup(str);
		new = ft_lstnew(tmp);
		ft_lstadd_back(&env, new);
	}
	return (1);
}

int	ft_export(t_data *data, int k)
{
	int		i;

	i = 1;
	g_var.exit_status = 0;
	if (data->cmds[k].cmds[1] == NULL)
		return (ft_print_env(data->env_2));
	else
	{
		while (data->cmds[k].cmds[i])
		{
			if (ft_is_identifier(data->cmds[k].cmds[i]))
				ft_add_to_env(data->env_2, data->cmds[k].cmds[i]);
			else
			{
				g_var.exit_status = 1;
				printf("minishell: export: not an identifier: %s\n", data->cmds[k].cmds[i]);
			}
			i++;
		}
	}
	return (1);
}
