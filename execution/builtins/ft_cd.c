/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:48:57 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 09:51:51 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int	update_pwd(t_list *env)
{
	char	cwd[PATH_MAX];
	char	*newpwd;
	t_list	*tmp;

	tmp = env;
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (0);
	newpwd = ft_strjoin("PWD=", cwd);
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->content, "PWD=", 4) == 0)
		{
			free(tmp->content);
			tmp->content = newpwd;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	go_to_home(t_data *data)
{
	char	*path;

	if (update_oldpwd(data->env_2) == 0)
		return (0);
	path = get_env_path(data->env_2, "HOME=", 5);
	if (path == NULL)
	{
		g_var.exit_status = 1;
		return (printf("minishell: cd: HOME not set\n"), 0);
	}
	if (chdir(path) == -1)
	{
		g_var.exit_status = 1;
		return (printf("minishell: cd: no such file or directory:  %s\n",
				path), 0);
	}
	update_pwd(data->env_2);
	return (1);
}

int	go_to_path(t_data *data, int k)
{
	char	*path;

	path = data->cmds[k].cmds[1];
	if (update_oldpwd(data->env_2) == 0)
		return (0);
	if (chdir(path) == -1)
	{
		g_var.exit_status = 1;
		return (printf("minishell: cd: no such file or directory: %s\n",
				path), 0);
	}
	update_pwd(data->env_2);
	return (1);
}

int	ft_cd(t_data *data, int k)
{
	g_var.exit_status = 0;
	if (data->cmds[k].cmds[1])
		return (go_to_path(data, k));
	else
		go_to_home(data);
	return (1);
}
