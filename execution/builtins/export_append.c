/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:58:57 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/26 22:06:00 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_strchr_app(const char *s, int c)
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

int ft_strncmp_app(char *str1, const char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i] && str1[i] != '=')
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    if ((str2[i] == '\0' && str1[i] == '=') || (str2[i] == '\0' && str1[i] == '\0'))
    {
        return (0);
    }
    return (str1[i] - str2[i]);
}

int ft_is_exist_envapp(t_list *env, const char *var)
{
    t_list *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp_app(tmp->content, var) == 0)
            return (1); // exist
        tmp = tmp->next;
    }
    return (0);
}

char *ft_add_char(char *src, char c)
{
    int lent_src;
    char *result;
    int i;

    result = 0;
    lent_src = ft_strlen(src);
    if ((result = (char *)ft_calloc(lent_src + 2, sizeof(char))) == NULL)
        return (minishell_perror(MEM));
    i = 0;
    while (i < lent_src)
    {
        result[i] = src[i];
        i++;
    }
    if (src)
        free(src);
    result[i] = c;
    result[i + 1] = '\0';
    return (result);
}

int update_env_app(t_list *env, char *var, char *value)
{
    t_list *tmp;
    char *result;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp_app(tmp->content, var) == 0)
        {
            if (ft_strchr_app(tmp->content, '=') - 1 == (int)ft_strlen(tmp->content))
                tmp->content = ft_add_char(tmp->content, '=');
            if (tmp->content == NULL)
                return (minishell_perror(MEM), 0);
            result = ft_strjoin(tmp->content, value);
            if (result == NULL)
                return (minishell_perror(MEM), 0);
            free(tmp->content);
            tmp->content = result;
            return (1);
        }
        tmp = tmp->next;
    }
    return (1);
}

int ft_append(t_list *env, char *str)
{
    char *variable;
    char *value;
    char *result;
    t_list *new;

    if ((variable = ft_substr(str, 0, ft_strchr_app(str, '+') - 1)) == NULL)
        return (minishell_perror(MEM), 0);
    if ((value = ft_substr(str, ft_strchr_app(str, '+') + 1, ft_strlen(str))) == NULL)
        return (minishell_perror(MEM), 0);
    if (ft_is_exist_envapp(env, variable))
        return (update_env_app(env, variable, value));
    else
    {
        if ((variable = ft_add_char(variable, '=')) == NULL)
            return (minishell_perror(MEM), 0);
        if ((result = ft_strjoin(variable, value)) == NULL)
        {
            free(variable);
            return (minishell_perror(MEM), 0);
        }
        if ((new = ft_lstnew(result)) == NULL)
        {
            free(variable);
            free(result);
            return (minishell_perror(MEM), 0);
        }
        free(variable);
        ft_lstadd_back(&env, new);
    }
    return (1);
}
