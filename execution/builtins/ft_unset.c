/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:49:49 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/22 11:24:22 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_is_identifier_unset(char *str)
{
    int i;

    i = 1;
    if (str[0] != '_' && ft_isalpha(str[0]) != 1)
        return (0);
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

int ft_strcmp_inset(char *s1, char *s2)
{
    size_t i;
    unsigned char str1;
    unsigned char str2;

    i = 0;
    while (s1[i] && s2[i])
    {
        str1 = (unsigned char)s1[i];
        str2 = (unsigned char)s2[i];
        if (str1 != str2)
            return (str1 - str2);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    if (s2[i] != '\0' || (s2[i] == '\0' && s1[i] != '='))
        return (-1);
    return (0);
}
void ft_remove_to_env(t_list *env, char *str)
{
    t_list *tmp;
    t_list *prev;

    tmp = env;
    while (tmp)
    {
        if (ft_strcmp_inset(tmp->content, str) == 0)
        {
            prev->next = tmp->next;
            free(tmp->content);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void ft_unset(t_data *data, int k)
{

    int i;

    i = 1;
    if (data->cmds[k].cmds[i] == NULL)
        return;
    else
    {
        while (data->cmds[k].cmds[i])
        {
            if (ft_is_identifier_unset(data->cmds[k].cmds[i]))
                ft_remove_to_env(data->env_2, data->cmds[k].cmds[i]);
            else
                printf("Minishel: unset: %s: not an identifier\n", data->cmds[k].cmds[i]);
            i++;
        }
    }
}