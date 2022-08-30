/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:50:32 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/30 15:51:14 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	update_oldpwd(t_list *env)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;
	t_list	*tmp;
	t_list	*new;

	tmp = env;
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (1);
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->content, "OLDPWD=", 7) == 0)
		{
			free(tmp->content);
			tmp->content = oldpwd;
			return (0);
		}
		tmp = tmp->next;
	}
	new = ft_lstnew(oldpwd);
	ft_lstadd_back(&env, new);
	return (0);
}

char	*get_env_path(t_list *env, const char *var, size_t len)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, len) == 0)
			return (ft_strchr(tmp->content, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}
