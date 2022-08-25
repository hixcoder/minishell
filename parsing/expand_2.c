/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:24:44 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/25 10:21:34 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_is_singl_qoted(char *s, int j)
{
    int i;
    int n1;
    int n2;
    int start;
    int end;

    start = 0;
    end = 0;
    n1 = 0;
    n2 = 0;
    i = -1;
    while (++i < j)
    {
        if (s[i] == '\'' && n2 % 2 == 0)
        {
            n1++;
            start = 1;
        }
        else if (s[i] == '\"' && n1 % 2 == 0)
        {
            n2++;
            start = 0;
        }
    }
    i--;
    while (s[++i])
    {
        if (s[i] == '\'')
        {
            end = 1;
            break ;
        }
    }
    if (start == 1 && end == 1 && n1 % 2 != 0)
        return (1);
    return (0);
}

// here I trim all things aroud the env var and return only its name that comes after the '$' sign.
char    *get_env_var_name(char *s)
{
    int i;
    int len;
    char *var_name;
    int j;

    i = -1;
    len = 0;
    while (s[++i])
    {
        if (s[i] == '_' || ft_isalnum(s[i]))
            len++;
        else
            break ;
    }
    if (!(var_name = malloc(sizeof(char) * (len + 2))))
        return (NULL);
    var_name[0] = '$';
    i = -1;
    j = 0;
    while(s[++i] && j < len)
    {
        if (s[i] == '_' || ft_isalnum(s[i]))
            var_name[++j] = s[i];
    }
    var_name[len + 1] = '\0';
    return (var_name);
}

// here I search for the env var value and return it.
char    *get_env_var_value(char **env, char *var_name)
{
    int i;
    char *tmp;
    char *tmp2;
    int var_name_len;
    
    i = -1;
    tmp2 = ft_strtrim(var_name, "$");
    var_name_len = ft_strlen(tmp2);
    while (env[++i])
    {
        tmp = ft_strnstr(env[i], tmp2, var_name_len);
        if (tmp != NULL)
        {
            if (tmp[var_name_len] == '=')
                return (tmp + (var_name_len + 1));
        }
    }
    return (NULL);
}

// this function check if there is an env var(start with '$') and expand it
char    *ft_expand_env_vars(char *s, char **env)
{
    int i;
    int j;
    char *tmp;
    char *tmp2;
    char *tmp3;
    char *new_s;

    i = -1;
    j = 0;
    tmp = NULL;
    new_s = s;
    while (s[++i])
    {
        if (s[i] == '$' && ft_is_singl_qoted(s, i+1) == 0)
        {
            tmp = get_env_var_name(&s[i+1]);
            tmp2 = new_s;
            tmp3 = get_env_var_value(env, tmp);
            new_s = ft_strreplace(new_s, tmp, tmp3, j);
            j += ft_strlen(tmp3) - ft_strlen(tmp) + 1;
            free(tmp);
            free(tmp2);
            // free(tmp3);
            // tmp = NULL;
        }
        else
            j++;
    }
    return (new_s);
}
