/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:46:34 by ahammam           #+#    #+#             */
/*   Updated: 2022/08/29 09:07:33 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <termios.h>
# include <sys/stat.h>
# include "./get_next_line/get_next_line.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define GREEN "\033[0;92m"
# define RED "\033[0;91m"
# define RESET "\033[0m"

// our types
typedef enum type
{
	ARG,
	REDIRECT_IN,
	REDIRECT_OUT,
	HERE_DOC,
	REDIRECT_OUT_APND,
	MY_FILE,
}	Type;

typedef struct s_word
{
	char	*w;
	Type	t;
} t_word;

// cmd : command
// words : atributes
typedef struct s_command
{
	char **cmds;
	t_word **words;
	char *path_bin;
} t_command;

typedef struct s_data
{
	char *args;
	t_command *cmds; // [echo "hello world", echo "hello world"]
	int cmds_len;
	char **env;
	t_list *env_2;
} t_data;

enum minishell_error
{
	MEM = 1,
	FORKERR = 2,
};

typedef struct s_sig
{
	int exit_status;
	pid_t pid_child;
	pid_t pid_herdoc;
	int is_killed;
	// int is_in_child;
} t_sig;

t_sig g_var;
void ft_readline(t_data *data);
void ft_error(char *error);

int is_insid_qots(char const *s, int j);
int ft_check_quotes(char *s);
char **ft_split2(char const *s, char c);
int ft_get_quotes_nbr(char *s);
char *ft_strreplace(char *s, char *old_w, char *new_w, int from);
Type ft_tokenize(char *word);
char *ft_check_redirections(char *s);
int ft_check_syntax(t_data *data, int check_nbr);
void ft_expander(t_data *data);
int ft_tokenizer(t_data *data);
int ft_spliter(t_data *data);
int ft_get_commands(t_data *data);
void ft_free(t_data *data);

char *ft_expand_env_vars(char *s, t_data *data);
char *ft_expand(t_data *data, char *s);

// echo
int ft_echo(t_command cmds);
// pwd
int ft_pwd();
// cd
int ft_cd(t_data *data, int k);

// env
int ft_env(t_data *data, int k);

// export
int		ft_export(t_data *data, int k);
int		ft_is_identifier(char *str);
int		ft_print_env(t_list *env);
int		ft_is_exist_env(t_list *env, const char *var);
int		ft_is_append(const char *str);
char	*ft_add_char(char *src, char c);
int		ft_append(t_list *env, char *str);
int		ft_lenstring(t_list *env);
char	*env_to_string(t_list *env);
int		ft_strncmp_env(const char *s1, const char *s2);

char *ft_pwd2(char *str);
// unset
int ft_unset(t_data *data, int k);

// remove it
char **ft_strsplit(char const *s, char c);
void ft_herdoc(t_data *data);

//
void ft_minishell(t_data *data);

void ft_trait_redir(t_data *data, int k, int *infile, int *outfile);

// fct buil
int ft_is_builtin(char *cmd);
void ft_execmd_built(t_data *data, int k);

int ft_exit(t_data *data, int k);
int ft_simple_cmd(t_data *data);
void ft_multiple_cmds(t_data *data);

void ft_execute_cmd(t_data *data, int k);
char *ft_get_bin(t_data *data, int k);
// exeve ve fct
void ft_execmd_bin(t_data *data, int k);
// minishell
void *minishell_perror(int err_type);

// signal
void ft_signal_handler(int sig);

char *ft_get_value(t_data *data, char *key);

void ft_print_error2(char *str, char *msg);
int ft_cmd_is_path(char *str);
void ft_dup2_close(int fd1, int fd2);

void get_exit_status(int status);

char *ft_get_file_name();
void ft_update_herdoc_info(t_data *data, int i, char *file_name);
void ft_create_herdoc_file(t_data *data, int i, int j, char *file_name);

// free fct
void ft_free_pipes(int **pipes);
void ft_free_split(char **split);
#endif