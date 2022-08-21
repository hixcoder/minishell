/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:12:00 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 13:02:42 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"

// our types
typedef enum type
{
	ARG,			   // word
	REDIRECT_IN,	   // '<'
	REDIRECT_OUT,	   // '>'
	HERE_DOC,		   // '<<'
	REDIRECT_OUT_APND, // '>>'

	FILE_IN,	  // word after '<'
	FILE_OUT,	  // word after '>'
	DELIMITER,	  // word after '<<'
	FILE_OUT_APND // word after '>>'
} Type;

typedef struct s_word
{
	char *w; // this is the word
	Type t;
} t_word;

typedef struct s_command
{
	t_word *cmd;
	t_word **atr;
	int fd_in;
	int fd_out;
} t_command;

typedef struct s_data
{
	char *args;
	t_command *cmds;

	int cmds_len;
	char **env;
	t_list *env_2;
} t_data;

void ft_readline(t_data *data);
void ft_error(char *error);

int is_insid_qots(char const *s, int j);
int ft_check_quotes(char *s);
char **ft_split2(char const *s, char c);
int ft_spliter(t_data *data);
void ft_expander(t_data *data);
char *ft_expand(char **env, char *s);
int ft_get_quotes_nbr(char *s);
char *ft_expand_env_vars(char *s, char **env);
char *ft_strreplace(char *s, char *old_w, char *new_w, int from);
void ft_tokenizer(t_data *data);
Type ft_tokenize(char *word);
char *ft_check_redirections(char *s);
int ft_check_syntax(t_data *data, int check_nbr);

// builtins
void ft_echo(t_command *cmd);
int ft_cd(t_data *data);
int ft_pwd();
int ft_export(t_data *data);

void ft_free_split(char **dst);
char *get_env_path(t_list *env, const char *var, size_t len);

// utile exportv
int ft_lenstring(t_list *env);
char *env_to_string(t_list *env);
void ft_sort_table(char **table);
int ft_is_identifier(char *str);
int ft_print_env(t_list *env);
void ft_append(t_list *env, char *str);

#endif