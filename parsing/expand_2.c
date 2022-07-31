/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:24:44 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/31 15:05:05 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_is_singl_qoted(char *s)
{
    int i;
    char end_qote;
    
    i = -1;
    while (s[++i])
    {
        if (s[i] == '\'' || s[i] == '\"')
            end_qote = s[i];
    }
    if (end_qote == '\'' == 1)
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
    int var_name_len;
    
    i = -1;
    var_name = ft_strtrim(var_name, "$");
    var_name_len = ft_strlen(var_name);
    while (env[++i])
    {
        tmp = ft_strnstr(env[i], var_name, var_name_len);
        if (tmp != NULL)
            return (tmp + (var_name_len + 1));
    }
    return (NULL);
}

// this function check if there is an env var(start with '$') and expand it
char    *ft_expand_env_vars(char *s, char **env)
{
    int i;
    char **tmp;
    char *new_s;

    i = -1;
    tmp = NULL;
    new_s = s;
    while (s[++i])
    {
        if (s[i] == '$' && ft_is_singl_qoted(&s[i+1]) == 0)
            tmp = ft_add_string(tmp, get_env_var_name(&s[i+1]));
    }
    if (!tmp)
        return (s);
    i = -1;
    while (tmp[++i])
    {
        new_s = ft_strreplace(new_s ,tmp[i], get_env_var_value(env, tmp[i]));
        free(tmp[i]);
    }
    tmp = NULL;
    return (new_s);
}
