/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:08:49 by ael-garr          #+#    #+#             */
/*   Updated: 2024/09/01 09:45:59 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
 #include <fcntl.h>
 

//int t_global;
t_minishell g_minishell;

void init_minishell()
{
	g_minishell.stdin = dup(0);
	g_minishell.stdout = dup(1);
}

// void	start_execution()
// {
// 	signal(SIGQUIT, SIGNAL_handler);
// }

void f()
{
	system("lsof -p $(pgrep minishell)");
}
int main(int argc, char	**argv, char **env)
{
	// char *s;
	((void)argc, (void)argv, (void)env);

	init_minishell();
	while (1)
	{
		// initialisation_of_signals()
		init_signals();
		atexit(f);
		g_minishell.line = readline(PROMPT); // NULL
		if (g_minishell.line && g_minishell.line[0])
			add_history(g_minishell.line);
		 if (g_minishell.line == NULL)
			break;
		// ls  -la
		//har *params[] = {"ls","-l", NULL};
		int a = open("main.c" , O_RDONLY);
		printf("%d\n",a);
		// v:vector
		// e: env
		// execve("/bin/ls",params, env);
		// perror(NULL); 
		// printf("error");
		// handling_if_line_is_empty
		// add_the_line_to_the_history
		// tokenization
		// handling_if_tokenisation_is_valid
		// start_execution
		// char *nametty = ttyname(0);
		// start_execution();
		
		// if(!g_minishell.line)
		// 	break;
	}
	

}