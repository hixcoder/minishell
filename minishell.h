/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:12:00 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/24 18:51:08 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include "./libft/libft.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

// our types
typedef enum type
{
	ARG,			   // word
	REDIRECT_IN,	   // '<'
	REDIRECT_OUT,	   // '>'
	HERE_DOC,		   // '<<'
	REDIRECT_OUT_APND, // '>>'
	MY_FILE,
	// FILE_IN, // word after '<'
	// FILE_OUT, // word after '>'
	// DELIMITER, // word after '<<'
	// FILE_OUT_APND // word after '>>'
} Type;

typedef struct s_word
{
	char *w; // this is the word
	Type t;
} t_word;

typedef struct s_redi
{
	t_word *redi;
	t_word *file;
} t_redi;

// cmd : command
// words : atributes
typedef struct s_command
{
	char **cmds; //
	t_word **words;
	t_redi **redi;
} t_command;

typedef struct s_data
{
	char *args;
	t_command *cmds;
	int cmds_len;
	char **env;
	t_list *env_2;
	int exit_status;
} t_data;

enum minishell_error
{
	MEM = 1,
	FORKERR = 2,
};

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
Type ft_tokenize(char *word);
char *ft_check_redirections(char *s);
int ft_check_syntax(t_data *data, int check_nbr);
void ft_expander(t_data *data);
int ft_tokenizer(t_data *data);
int ft_spliter(t_data *data);
int ft_redirector(t_data *data);

// echo
int ft_echo(t_command cmds);
// pwd
int ft_pwd();
// cd
int ft_cd(t_data *data, int k);
// env
int ft_env(t_data *data, int k);
// utile exportv
int ft_export(t_data *data, int k);
int ft_lenstring(t_list *env);
char *env_to_string(t_list *env);
void ft_sort_table(char **table);
int ft_is_identifier(char *str);
int ft_print_env(t_list *env);
int ft_append(t_list *env, char *str);
// unset
int ft_unset(t_data *data, int k);
int ft_exit(t_data *data, int k);

// mi
void ft_minishell(t_data *data);

void ft_trait_redir(t_data *data, int k, int *infile, int *outfile);

// fct buil
int ft_is_builtin(char *cmd);
void ft_execmd_built(t_data *data, int k);

int ft_simple_cmd(t_data *data);
void ft_multiple_cmds(t_data *data);

void ft_execute_cmd(t_data *data, int k);

// exeve ve fct
void ft_execmd_bin(t_data *data, int k);
// minishell
void *minishell_perror(int err_type);
#endif