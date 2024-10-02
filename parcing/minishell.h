/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:58:15 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/02 16:02:47 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
    char    *content;
    char    *type;    
    struct s_list  *next;
    char    *command;
} t_list;

// list utils
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// helper funcions
char	**ft_split_space(char const *s);
int     ft_strncmp(char *s1, char *s2, size_t n);
size_t  ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);


// parcing functiong
t_list  *parsing(char *str);
int     parse_word(char *str, int i, t_list **lst);
int     parse_spaces(char *str, int i, t_list **lst);
void    classing(t_list **lst)

// syntax functions
int    check_redirection_followed_by_pipe(t_list *lst);
int    check_consecutive_pipes(t_list *lst);
int    is_space(t_list *token);
int    is_valid_next(t_list *token);
int    syntax1(t_list **lst);
int    syntax2(t_list **lst);
int    syntax3(t_list **lst);
int    syntax4(t_list **lst);
int    syntax(t_list **lst);
int     error_message();





#endif