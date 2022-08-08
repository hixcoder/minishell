/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:44:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/08 13:14:13 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_spaces_before(char *s, int i)
{
    int j;

    j = -1;
    while (++j < i)
    {
        if (s[j] != ' ')
            return (0);
    }
    return (1);
}

// given the string "s"
// this function check if there is any special character not in this list (>, <, ", ', space, |, $, ?, alphanum)
int ft_check_specials(char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (is_insid_qots(s, i) == 0 && s[i] != '>' && s[i] != '<' && 
            s[i] != '\"' && s[i] != '\'' && s[i] != ' ' && s[i] != '|' &&
            s[i] != '-' && s[i] != '_' && 
            s[i] != '$' && s[i] != '?' && ft_isalnum(s[i]) == 0)
            return (1);
        if ((s[i] == '|' && is_insid_qots(s, i) == 0 && 
            s[i + 1] == '|' && is_insid_qots(s, i + 1) == 0) ||
            (s[i] == '|' && is_spaces_before(s, i) == 1))
            return (1);
    }
    if (s[i - 1] == '|')
        return (1);
    return (0);
}

int ft_check_syntax(t_data *data, int check_nbr)
{
    // check if quotes are closed or not
    if (check_nbr == 0)
		printf("syntax error\n");
    else if (check_nbr == 1)
    {
        if (ft_check_quotes(data->args) == 1)
		{
			printf("syntax error: unclosed quotes\n");
			return (1);
		}
    }
    // check if there is any special character not in this list (>, <, ", ', space, |, $, ?)
    else if (check_nbr == 2)
    {
        if (ft_check_specials(data->args) == 1)
		{
			printf("syntax error: unhandled special character\n");
			return (1);
		}
    }
    return (0);
}