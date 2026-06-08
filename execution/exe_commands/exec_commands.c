/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:18:08 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/21 12:49:04 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_much_cmnd(t_minishell *data, char *path, int in, int out, int upipe)
{
	int	fork_res;

	fork_res = fork();
	if (fork_res == -1)
		perror("forking :");
	else if (fork_res == 0)
	{
		dprintf(2, "inside the (exec_much_commands >>> %d\n)",getpid());
		close(upipe);
		if (out)
		{
			dup2(out, 1);
			close(out);
		}
		if (in)
		{
			dup2(in, 0);
			close(in);
		}
		// execve (check_acces(data, ft_split(path,' ')[0]), ft_split(path, ' '), data->env);
		execve(check_acces(data, data->commands->args[0]), data->commands->args, data->env);
		ft_putstr_fd (PROMPT, 2);
		perror (path);
	}
	return (0);
}

// int	exe_commands(t_minishell *data)
// {
// 	int	table_size;
// 	int	pipe_fd[2];
// 	int	i;

// 	i = 0;
// 	data->__stdinp = dup(0);
// 	data->__stdoutp = dup(1);
// 	table_size = ft_lstsize_c(data->commands);
// 	if (pipe(pipe_fd) == -1)
// 		perror (PROMPT);
// 	while (i < table_size)
// 	{
// 		if (i == 0)
// 			exec_much_cmnd(data, data->commands[i], 0, pipe_fd[1], pipe_fd[0]);
// 		if (i == 1)
// 			exec_much_cmnd(data, data->commands[i], pipe_fd[0], 0, pipe_fd[1]);
// 		i++;
// 		// ft_free_table(&data->commands)
// 	}
// 	close (pipe_fd[0]);
// 	close (pipe_fd[1]);
// 	int status = 0;
// 	while (waitpid(-1, &status, 0) != -1)
// 		;
// 	dprintf (2, "%d\n", status);
// 	return (0);
// }
