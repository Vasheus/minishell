/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:43:06 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/23 19:54:03 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	initialize_fds(int ***table, int n)
{
	int	i;

	i = 0;
	*table = malloc(n * sizeof(int *));
	if (!(*table))
		return (-1);
	while (i < n)
	{
		(*table)[i] = malloc(2 * sizeof(int));
		if (!(*table)[i])
			return (-1);
		i++;
	}
	return (i);
}

void	close_fd(int *n)
{
	if (!n)
		return;
	while (*n > 0)
	{
		close(*n);
		n++;
	}
}

void	multi_util(t_minishell *data, char **cmd, int read_fd, int print, int *to_close)
{
	int fork_res;

	fork_res = fork();
	if (fork_res == -1)
		return (perror("forking"));
	if (fork_res == 0)
	{
		close_fd(to_close);
		if (read_fd != 0)
		{
			if (dup2(read_fd, 0) == -1)
				perror("dup2 read_fd");
			close(read_fd);
		}
		if (print != 1)
		{
			if (dup2(print, 1) == -1)
				perror(cmd[0]);
			close(print);
		}
		execve(check_acces(data, cmd[0]), cmd, data->env);
		perror("child execve");
		puts("ERROR INSIDE THE MUSH COMMANDS FUN\n");
		// ft_free_table(&args);
		// exit(EXIT_FAILURE);
	}
	
}

int	multi_commands(t_minishell	*data)
{
	set_args	*args;
	int			size;
	int			**pipe_fd;
	int			i;

	// puts("multi commands had started\n");
	args = data->commands;
	size = ft_lstsize_c(args);
	if (initialize_fds(&pipe_fd, size - 1) == -1)
		return (-1);
	i = 0;
	while (i < (size))
	{
		if ((i < size - 1))
		{
			if (pipe(pipe_fd[i]) != 0)
				return(perror("pipe error"), -1);
		}
		if (i == 0)
			multi_util(data, args->args, 0, pipe_fd[0][1], (int[]){pipe_fd[0][0], -1});
		else if (i == (size -1))
			multi_util(data, args->args, pipe_fd[i - 1][0], 1, (int[]){pipe_fd[i - 1][1], -1});
		else
			multi_util(data, args->args, pipe_fd[i - 1][0], pipe_fd[i][1], (int[]){pipe_fd[i-1][1], pipe_fd[i][0], -1}); 
		if (i > 0)
		{
			close(pipe_fd[i - 1][0]);
		}
		if (i < size - 1)
			close(pipe_fd[i][1]);
		i++;
		args = args->next;
	}
    // Close any remaining pipe ends (cleanup)
	int j=0;
	while(j < size - 1)
	{
		close(pipe_fd[j][0]);
		close(pipe_fd[j][1]);
		j++;
	}
	while (waitpid(-1, &data->status, 0) != -1)
		;
	if(WIFEXITED(data->status))
		data->exit_s = WEXITSTATUS(data->status);
	else if (WIFSIGNALED(data->status))
		data->exit_s = WTERMSIG(data->status);
	else 
		data->exit_s =89;
	printf("the status after executiong too much commands is>>%d\n",data->exit_s);
	return (0);
}
