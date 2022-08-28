/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:23:26 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/28 16:21:51 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_vars
{
    int i;
	int j;
	char *old_s;
	char *new_s;
	char *tmp_d;
	char *tmp_d_with_space;
	char **c;
}	t_vars;

char	*is_delimiter(char **c, char *s)
{
	int i;

	i = -1;
	while (c[++i])
	{
		if (ft_memcmp(c[i], s, ft_strlen(c[i])) == 0)
			return (c[i]);
	}
	return (NULL);
}

char *ft_add_spaces(char *c)
{
	char *s;
	int c_len;

	c_len = ft_strlen(c);
	if (!(s = malloc(sizeof(char) * c_len + 2)))
		return (NULL);
	s[0] = ' ';
	ft_memcpy(&s[1], c, c_len);
	s[c_len + 1] = ' ';
	s[c_len + 2] = '\0';
	return (s);
}

void    ft_init_vars(t_vars *var, char *s)
{
    var->c = malloc(sizeof(char *) * 5);
	var->c[0] = ">>";
	var->c[1] = "<<";
	var->c[2] = ">";
    var->c[3] = "<";
	var->c[4] = NULL;
	var->i = -1;
	var->j = 0;
	var->new_s = s;
}

// given a string 's'
// the job is to find redirections [>,<,>>,<<] and add a space 
// before and after them if they are not inside a double or single quotes
// ex: s = ls>k>>fi<"<<ju" ==> new_s = ls > k >> fi < "<<ju" 
char	*ft_check_redirections(char *s)
{
	// dragon cleaner
	t_vars var;
	// int is_redi_exist;
    
    ft_init_vars(&var, s);
	// is_redi_exist = 0;
	while (s[++var.i])
	{
		var.tmp_d = is_delimiter(var.c, &s[var.i]);
		if (var.tmp_d != NULL && is_insid_qots(s, var.i) == 0)
		{
			// is_redi_exist = 1;
			var.tmp_d_with_space = ft_add_spaces(var.tmp_d);
			var.old_s = var.new_s;
			var.new_s = ft_strreplace(var.old_s, var.tmp_d, var.tmp_d_with_space, var.j);
			free(var.old_s);
			var.j += ft_strlen(var.tmp_d_with_space);
			var.i += ft_strlen(var.tmp_d) - 1;
			free(var.tmp_d_with_space);
		}
		else
			var.j++;
	}
	// if (is_redi_exist == 1)
	// 	free(s);
    free(var.c);
	var.c = NULL;
	return (var.new_s);
}
