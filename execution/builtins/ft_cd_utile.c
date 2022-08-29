/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:50:32 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 09:54:11 by ahammam          ###   ########.fr       */
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
		return (0);
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
