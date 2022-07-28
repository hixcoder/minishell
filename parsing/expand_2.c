/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:24:44 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/28 13:18:42 by hboumahd         ###   ########.fr       */
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
    if (!(var_name = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = -1;
    j = -1;
    while(s[++i] && j < len)
    {
        if (s[i] == '_' || ft_isalnum(s[i]))
            var_name[++j] = s[i];
    }
    var_name[len] = '\0';
    return (var_name);
}

// here I search for the env var value and return it.
char    *get_env_var_value(char **env, char *var_name)
{
    int i;
    char *tmp;
    int var_name_len;
    
    i = -1;
    var_name_len = ft_strlen(var_name);
    while (env[++i])
    {
        tmp = ft_strnstr(env[i], var_name, var_name_len);
        if (tmp != NULL)
            return (tmp + (var_name_len + 1));
    }
    return (NULL);
}


 // now you should know the exact name of the env var (alphamum type) then do this:
 // 1- splite with $
 // 2- give the env var its value (use strstr to search in the env)
 // 3- join the strings and return them in one string

// this check if there is an env var(start with '$') and expand it
// sInd : is the space index
void    ft_expand_env_vars(char *s, char **env)
{
    int i;
    int sInd;

    i = -1;
    sInd = 0;
    (void) env;
    while (s[++i])
    {
        if (s[i] == '$' && ft_is_singl_qoted(&s[i+1]) == 0)
        {
            
            
            printf("%s \n",ft_strreplace(&s[i] ,get_env_var_name(&s[i+1]), get_env_var_value(env, get_env_var_name(&s[i+1]))));
            printf("");
        }
    }
}
// hello $d hh $d ==> 
/*
d=55
hello
d hh 
d
*/