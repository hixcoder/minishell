/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:23:08 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/28 10:03:50 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_strchr_env(const char *s, int c)
{
    int i;
    char *ps;
    char uc;

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

int ft_is_append(const char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '=')
    {
        if (str[i] == '+')
            return (1);
        i++;
    }
    return (0);
}

int ft_is_char_exist(char *str, char c)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (i);
}

int ft_strncmp_env(const char *s1, const char *s2)
{
    size_t i;
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

int ft_is_exist_env(t_list *env, const char *var)
{
    t_list *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp_env(tmp->content, var) == 0)
            return (1); // exist
        tmp = tmp->next;
    }
    return (0);
}

int update_env(t_list *env, char *par)
{
    t_list *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp_env(tmp->content, par) == 0)
        {
            free(tmp->content);
            if (ft_is_char_exist(par, '=') == (int)ft_strlen(par) && (((char *)(tmp->content))[ft_is_char_exist(tmp->content, '=')] != '\0'))
                tmp->content = ft_strjoin(par, "=");
            else
                tmp->content = ft_strdup(par);
            if (tmp->content == NULL)
                return (minishell_perror(MEM), 0);
            return (1);
        }
        tmp = tmp->next;
    }
    return (1);
}

int ft_add_to_env(t_list *env, char *str)
{
    t_list *new;

    if (ft_is_append(str))
        return (ft_append(env, str));
    else if (ft_is_exist_env(env, str))
        return (update_env(env, str));
    else
    {
        if ((new = ft_lstnew(str)) == NULL)
            return (minishell_perror(MEM), 0);
        ft_lstadd_back(&env, new);
    }
    return (1);
}

int ft_export(t_data *data, int k)
{
    int i;

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
                printf("export: not an identifier: %s\n", data->cmds[k].cmds[i]);
            }
            i++;
        }
    }
    return (1);
}
