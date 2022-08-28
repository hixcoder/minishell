/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:41:37 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/27 23:48:06 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_pwd()
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX))
    {
        printf("%s\n", cwd);
        return (1);
    }
    else
        return (0);
}

char *ft_pwd2(char *str)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX))
        return (ft_strjoin(str, cwd));
    return (NULL);
}