/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:41:19 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/24 19:57:09 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEEL_H
#define MINISHEEL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <stdbool.h>
# include "libft.h"
# include "../../parcing/parcing.h"
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>
# define	PROMPT	"minishell$ "
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int g_signal;
typedef struct s_environ
{
	char *var;
	char *value;
	// t_type	type;
	struct s_environ *next;
}	t_environ;
                             //**************************************
typedef enum e_tags{
	COMMAND_NOT_FOUND,
	TOO_MANY_ARGS,
	NUMRC_ARG_REQUIRED,
	PERM_ERROR,
	NOSUCHFORD,
}	t_tags;

typedef enum e_no{
	ENO_SUCCESS,
	ENO_TOO_MANY_ARGS,
	ENO_GENERAL,
	ENO_CMMND_NT_FOND,
	ENO_CANT_EXEC = 126,
	ENO_EXEC_255 = 255,
}	t_no;

typedef struct e_error{
	t_tags tag;
	t_no error_no;
	char *cause;
} t_error;
                             //**************************************

// typedef enum e_token_type
// {
// 	T_IDENTIFIER,
// 	T_LESS,
// 	T_GREAT,
// 	T_DLESS,
// 	T_DGREAT,
// 	T_PIPE,
// 	T_O_PARENT,
// 	T_C_PARENT,
// 	T_AND,
// 	T_OR,
// 	T_NL,
// }	t_token_type;

// typedef enum s_type
// {
// 	BUILT_in,
// 	SIMPE_COMMAND,

// }	t_type;

// typedef struct s_token
// {
// 	t_token_type		type;
// 	char				*value;
// 	struct s_token		*next;
// 	struct s_token		*prev;
// }	t_token;

typedef struct s_minishell
{
	char	*line;
	char	**env;
	// char	**args;
	// char **commands;
	// t_type	type;
	// t_token			*tokens;
	t_environ *env_lst;
	int exit_s;
	int status;
	int stdin;
	int stdout;
	char	*old_path;
	// char	*content;
	set_args	*commands;
	t_list	*list;
}	t_minishell;
// extern t_minishell g_minishell;
//    *******   GARBAGE     **************
// t_token	*ft_tokenize(void);
// int	ft_append_identifier(char **line_ptr, t_token **token_list);
// int	ft_handle_separator(char **line_ptr, t_token **token_list);
// void	ft_skip_spaces(char **line);
// int	ft_isspace(char c);
// void	ft_clear_token_list(t_token **lst);
// t_token	*ft_tokenization_handler(char *line);
// FUNCTIONS********
// void	ft_putstr_fd(char *s, int fd);
int	start_execution(t_minishell	*data);
// void	init_signals(void);
void	ctl_d_signal(int sig);
		// ************BUITL_INS***************
int	ft_cd(t_minishell *data);
int	ft_echo(t_minishell *data);
int	ft_ls(t_minishell *data);
int	ft_env(t_minishell *data);
int	ft_error(/*t_minishell *data,*/char	*first, t_tags message);
int	ft_exit(t_minishell *data);
int	to_alloc(char *s ,char c);
int	ft_pwd(t_minishell *data);
		// ************BUITL_INS***************     >>>>   export
int	final_update(t_minishell *data, char *key, char *value, bool create);
int	ft_export(t_minishell *data);
int	ft_error_export_2_args(/*t_minishell *data,*/char *fctn_name, char *command);
char	 *extract_key(char *string);
int	check_syntax_for_export(char *string);
char	*extract_value(char *line);
int	ft_err_msg(t_error error);
int	print_export(t_minishell *data);
t_environ *create_list(t_minishell *data);
t_environ	*ft_lstnew_env(char *var, char *value);
int	ft_lstsize(t_environ	*lst);
int	sort_and_print(/*t_minishell *data,*/char **table);
void	ft_lstadd_back_env(t_environ **lst, t_environ *new);
int	count_table_entries(char **table);
int ft_unset(t_minishell *data);
char	*ft_find_node(t_minishell *data, char	*str);
		// ************BUITL_INS***************     >>>>   export
int	exec_smpl_cmnd(t_minishell *data);
		// ************UTILS***************
int	ft_free_table(char	***table);
int	free_table(t_minishell *data);
char	*joinning_and_free(char *s1, char	*s2);
char	*check_acces(t_minishell *data, char *ftn);
		// ************MULTI COMMANDS***************     >>>>   export
int	exe_commands(t_minishell *data);
int	multi_commands(t_minishell *data);
		// ************TEMPOPARY***************     >>>>   export
int small_parse(t_minishell *data, char *cmd);
		// ************SIGNALS***************     >>>>   signals
void	init_signl(void);
void	ctrl_c_sig(int sig);
		// ************FOR_NERGING***************     >>>>   youssef
int		ft_lstsize_m(t_list	*lst);		
int		ft_lstsize_c(set_args	*lst);
		// ************FOR_TESTING***************     >>>>  
void	test_node_content(t_minishell *data);
void	test_list_content(t_minishell *data);
void	c_collector(t_minishell *data);
int		joinning_for_print(t_environ **node, char **list);
#endif