/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:16:33 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/20 16:43:44 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_env_path(t_list *env, const char *var, size_t len)
{
    t_list *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp(tmp->content, var, len) == 0)
            return (ft_strchr(tmp->content, '=') + 1);
        tmp = tmp->next;
    }
    return (NULL);
}

int update_oldpwd(t_list *env)
{
    char cwd[PATH_MAX];
    char *oldpwd;
    t_list *tmp;
    t_list *new;

    tmp = env;
    if (getcwd(cwd, PATH_MAX) == NULL)
        return (0);
    if (!(oldpwd = ft_strjoin("OLDPWD=", cwd)))
        return (0);
    while (tmp)
    {
        if (ft_strncmp((char *)tmp->content, "OLDPWD=", 7) == 0)
        {
            free(tmp->content);
            tmp->content = oldpwd;
            return (1);
        }
        tmp = tmp->next;
    }
    new = ft_lstnew(oldpwd);
    ft_lstadd_back(&env, new);
    return (0);
}

int update_pwd(t_list *env)
{

    char cwd[PATH_MAX];
    char *newpwd;
    t_list *tmp;

    tmp = env;
    if (getcwd(cwd, PATH_MAX) == NULL)
        return (0);
    if (!(newpwd = ft_strjoin("PWD=", cwd)))
        return (0);
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

int go_to_home(t_data *data)
{
    char *path;

    if (update_oldpwd(data->env_2) == 0)
        return (0);
    if ((path = get_env_path(data->env_2, "HOME=", 5)) == NULL)
        return (printf("minishell: cd: HOME not set\n"), 0);
    if (chdir(path) == -1)
        return (printf("minishell: cd: no such file or directory: %s\n", path), 0);
    update_pwd(data->env_2);
    return (1);
}

int go_to_path(t_data *data)
{
    char *path;

    path = data->cmds->atr[0]->w;
    if (update_oldpwd(data->env_2) == 0)
        return (0);
    if (chdir(path) == -1)
        return (printf("minishell: cd: no such file or directory: %s\n", path), 0);
    update_pwd(data->env_2);

    return (1);
}

int ft_cd(t_data *data)
{
    t_command *cmds;

    cmds = data->cmds;
    if (cmds->atr[0])
        return (go_to_path(data));
    else
        go_to_home(data);
    return (1);
}