/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 18:17:16 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_is_empty(t_data *data)
{
	t_list	*head;
	t_list	*next1;
	t_list	*next2;

	head = ft_lstnew(ft_strdup("SHLVL=1"));
	next1 = ft_lstnew(ft_pwd2("PWD="));
	next2 = ft_lstnew(ft_pwd2("OLDPWD="));
	ft_lstadd_back(&head, next1);
	ft_lstadd_back(&head, next2);
	data->env_2 = head;
	return (0);
}

typedef struct s_env_par
{
	int		i;
	t_list	*head;
	t_list	*new;
	char	*content;
	int		lvl;
}	t_env_par;

void	ft_shlvl_noexit(t_env_par *par)
{
	if (par->lvl == -2)
	{
		par->content = ft_strdup("SHLVL=1");
		par->new = ft_lstnew(par->content);
		ft_lstadd_back(&(par->head), par->new);
	}
}

void	ft_body_envshl(t_env_par *par, char **env)
{
	char	*tmp;

	if (!ft_strncmp(env[par->i], "SHLVL", 5) && ((env[par->i])[5] == '='))
	{
		par->lvl = ft_atoi(env[par->i] + 6);
		if (par->lvl < 0)
			par->lvl = -1;
		tmp = ft_itoa(par->lvl + 1);
		par->content = ft_strjoin("SHLVL=", tmp);
		free(tmp);
	}
	else
		par->content = ft_strdup(env[par->i]);
	par->new = ft_lstnew(par->content);
	ft_lstadd_back(&par->head, par->new);
}

int	init_env(t_data *data, char **env)
{
	t_env_par	par;

	par.i = 1;
	par.lvl = -2;
	if (env[0] == NULL)
		return (ft_env_is_empty(data));
	par.content = ft_strdup(env[0]);
	par.head = ft_lstnew(par.content);
	while (env[par.i])
	{
		ft_body_envshl(&par, env);
		par.i = par.i + 1;
	}
	ft_shlvl_noexit(&par);
	data->env_2 = par.head;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)av;
	(void)ac;
	(void)env;
	init_env(&data, env);
	g_var.exit_status = 0;
	ft_readline(&data);
	ft_lstclear(&data.env_2, free);
	return (0);
}
