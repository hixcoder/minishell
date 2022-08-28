/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:46:44 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/28 21:27:25 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_lenstring(t_list *env)
{
    t_list *tmp;
    int nbr;

    tmp = env;
    nbr = 0;
    while (tmp)
    {
        nbr = nbr + ft_strlen(tmp->content) + 1;
        tmp = tmp->next;
    }
    return (nbr);
}

char *env_to_string(t_list *env)
{
    char *result;
    t_list *tmp;

    tmp = env;
    if (!(result = (char *)malloc(sizeof(char) * ft_lenstring(env) + 1)))
        return (minishell_perror(MEM));
    while (tmp)
    {
        if ((result = ft_strcat(result, (char *)tmp->content)) == NULL)
            return (minishell_perror(MEM));

        tmp = tmp->next;
    }
    return (result);
}

void ft_sort_table(char **table)
{
    int i;
    int j;
    char *min;

    i = 0;
    while (table[i])
    {
        min = table[i];
        j = i + 1;
        while (table[j])
        {
            if (ft_strcmp(table[j], min) < 0)
            {
                table[i] = table[j];
                table[j] = min;
                min = table[i];
            }
            j++;
        }
        i++;
    }
}

int ft_is_identifier(char *str)
{
    int i;

    i = 1;
    if (str[0] != '_' && ft_isalpha(str[0]) != 1)
        return (0);
    while (str[i] && str[i] != '=')
    {
        if (str[i] == '+' && str[i + 1] == '=')
            ;
        else if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

void ft_sort_env(t_list *env)
{
    t_list *tmp;
    t_list *tmp2;
    char *min;

    tmp = env;

    while (tmp)
    {
        tmp2 = tmp;
        min = tmp->content;
        while (tmp2)
        {
            if (ft_strcmp(tmp2->content, min) < 0)
            {
                tmp->content = tmp2->content;
                tmp2->content = min;
                min = tmp->content;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

t_list *ft_duplicat_env(t_list *env)
{
    t_list *tmp;
    t_list *result;
    t_list *new;
    char *str;

    tmp = env;
    result = NULL;
    while (tmp)
    {
        if (!(str = ft_strdup(tmp->content)))
            return (minishell_perror(MEM));
        if ((new = ft_lstnew(str)) == NULL)
            return (minishell_perror(MEM));
        ft_lstadd_back(&result, new);
        tmp = tmp->next;
    }
    return (result);
}

int ft_print_env(t_list *env)
{
    t_list *tmp;
    t_list *tmp2;
    char *str;
    int i;
    char *c;

    i = 0;
    c = "";
    if (((tmp = ft_duplicat_env(env)) == NULL))
        return (minishell_perror(MEM), 0);
    tmp2 = tmp;
    ft_sort_env(tmp);
    while (tmp)
    {
        printf("declare -x ");
        i = 0;
        c = "";
        str = tmp->content;
        while (str[i])
        {
            printf("%c", str[i]);
            if (str[i] == '=' && (c = "\""))
                printf("\"");
            i++;
        }
        printf("%s\n", c);
        tmp = tmp->next;
    }
    ft_lstclear(&tmp2, free);
    return (1);
}