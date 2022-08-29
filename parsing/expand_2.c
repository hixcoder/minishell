/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:24:44 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/29 11:03:50 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_qot_var
{
	int		i;
	int		n1;
	int		n2;
	int		start;
	int		end;
	char	*s;
	int		j;
}	t_qot_var;

typedef struct s_get_env_var_name
{
	int		i;
	int		len;
	char	*var_name;
	int		j;
}	t_name_var;

typedef struct s_ft_expand_env_vars
{
	int		i;
	int		j;
	char	*var_name;
	char	*var_value;
	char	*new_s;
}	t_expand_env_vars;

void	ft_check_the_beginning(t_qot_var *qot_var)
{
	qot_var->start = 0;
	qot_var->n1 = 0;
	qot_var->n2 = 0;
	qot_var->i = -1;
	while (++qot_var->i < qot_var->j)
	{
		if (qot_var->s[qot_var->i] == '\'' && qot_var->n2 % 2 == 0)
		{
			qot_var->n1++;
			qot_var->start = 1;
		}
		else if (qot_var->s[qot_var->i] == '\"' && qot_var->n1 % 2 == 0)
		{
			qot_var->n2++;
			qot_var->start = 0;
		}
	}
	qot_var->i--;
}

int	ft_is_singl_qoted(char *s, int j)
{
	t_qot_var	qot_var;

	qot_var.s = s;
	qot_var.j = j;
	ft_check_the_beginning(&qot_var);
	qot_var.end = 0;
	while (s[++qot_var.i])
	{
		if (s[qot_var.i] == '\'')
		{
			qot_var.end = 1;
			break ;
		}
	}
	if (qot_var.start == 1 && qot_var.end == 1 && qot_var.n1 % 2 != 0)
		return (1);
	return (0);
}

// here I trim all things aroud the env var and return
// only its name that comes after the '$' sign.
char	*get_env_var_name(char *s)
{
	t_name_var	name_var;

	name_var.i = -1;
	name_var.len = 0;
	while (s[++name_var.i])
	{
		if (s[name_var.i] == '_' || ft_isalnum(s[name_var.i]))
			name_var.len++;
		else
			break ;
	}
	name_var.var_name = malloc(sizeof(char) * (name_var.len + 2));
	if (name_var.var_name == NULL)
		return (ft_error_mallocation(), NULL);
	name_var.var_name[0] = '$';
	name_var.i = -1;
	name_var.j = 0;
	while (s[++name_var.i] && name_var.j < name_var.len)
	{
		if (s[name_var.i] == '_' || ft_isalnum(s[name_var.i]))
			name_var.var_name[++name_var.j] = s[name_var.i];
	}
	name_var.var_name[name_var.len + 1] = '\0';
	return (name_var.var_name);
}

// this function check if there is an env var(start with '$') and expand it
char	*ft_expand_env_vars(char *s, t_data *data)
{
	t_expand_env_vars	vars;

	vars.i = -1;
	vars.j = 0;
	vars.var_name = NULL;
	vars.new_s = s;
	while (s[++vars.i])
	{
		if (s[vars.i] == '$' && ft_is_singl_qoted(s, vars.i + 1) == 0)
		{
			vars.var_name = get_env_var_name(&s[vars.i + 1]);
			if (strncmp(vars.var_name, "$?", ft_strlen(vars.var_name)) == 0)
				continue ;
			vars.var_value = ft_get_value(data, vars.var_name + 1);
			vars.new_s = ft_strreplace(vars.new_s, vars.var_name, \
			vars.var_value, vars.j);
			vars.j += ft_strlen(vars.var_value) - ft_strlen(vars.var_name) + 1;
			free(vars.var_name);
			vars.var_name = NULL;
		}
		else
			vars.j++;
	}
	return (vars.new_s);
}
