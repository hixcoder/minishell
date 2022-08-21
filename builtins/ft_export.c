/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:23:08 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/21 14:16:58 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
    while (str[i])
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
    unsigned char str1;
    unsigned char str2;
    size_t len1 = 0;
    size_t len2 = 0;

    len1 = ft_is_char_exist((char *)s1, '=');
    len2 = ft_is_char_exist((char *)s2, '='); // export value
    i = 0;
    while (i < len1 && i < len2)
    {
        str1 = (unsigned char)s1[i];
        str2 = (unsigned char)s2[i];
        if (str1 != str2)
            return (str1 - str2);
        i++;
    }
    if (s2[i] == '\0' && s1[i] != '=')
        return (s1[i] - s2[i]);
    if ((s2[i] == '\0' && s1[i] == '=') || (s1[i] == '\0' && s2[i] == '='))
        return (0);
    if ((s2[i] == '=' && s1[i] != '=') || (s1[i] == '=' && s2[i] != '='))
        return (s1[i] - s2[i]);
    return (0);
}

int ft_is_exist_env(t_list *env, const char *var)
{
    t_list *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp_env(tmp->content, var) == 0)
            return (1); // kayn
        tmp = tmp->next;
    }
    return (0);
}

void update_env(t_list *env, char *par)
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
            return;
        }
        tmp = tmp->next;
    }
}

int ft_add_to_env(t_list *env, char *str)
{
    t_list *new;

    if (ft_is_append(str))
        ft_append(env, str);
    else if (ft_is_exist_env(env, str))
        update_env(env, str);
    else
    {
        if ((new = ft_lstnew(str)) == NULL)
            return (0);
        ft_lstadd_back(&env, new);
    }
    return (1);
}

int ft_export(t_data *data)
{
    t_command *cmds;
    int i;

    cmds = data->cmds;
    i = 0;
    if (cmds->atr[0] == NULL)
        return (ft_print_env(data->env_2));
    else
    {
        while (cmds->atr[i])
        {
            if (ft_is_identifier(cmds->atr[i]->w))
                ft_add_to_env(data->env_2, cmds->atr[i]->w);
            else
                printf("export: not an identifier: %s\n", cmds->atr[i]->w);
            i++;
        }
    }
    return 0;
}
