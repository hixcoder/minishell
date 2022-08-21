/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:11:44 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/21 16:45:31 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_is_char_instring(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void ft_env(t_data *data)
{
    t_list *tmp;

    tmp = data->env_2;
    while (tmp)
    {
        if (ft_is_char_instring(tmp->content, '='))
            printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
}