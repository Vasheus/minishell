/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:47:49 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/24 20:18:13 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	waitpid_fnc(t_minishell *data,int pid)
{
	pid_t	wait;
	int		status;

	wait = waitpid(pid ,&status, 0);
	if (wait == -1)
		return (wait);
	if (WIFEXITED(status) || status == ENOEXEC)
		data->exit_s = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data->exit_s = WTERMSIG(status) + 128;
	// else
		// data->exit_s = 1;
	return (0);
}

char	*check_acces(t_minishell *data, char *ftn)
{
	char	**table;
	char	*path;
	int		i;
	char	*node_contet;

	table = NULL;
	i = 0;
	if (!ftn || !data->env_lst)
		return (NULL);
	if (access (ftn, X_OK) == 0)
		return (ft_strdup(ftn));
	else
	{
		if (!(node_contet = ft_find_node(data, "PATH")))
			return (free_table(data), NULL);
		table = ft_split(node_contet, ':');
		while (i < count_table_entries(table))
		{
			path = ft_strjoin(table[i], "/");
			path = joinning_and_free(path, ftn);
			if (access (path, X_OK) == 0)
			{
				ft_free_table (&table);
				free (node_contet);
				return (path);
			}
			free (path);
			i++;
		}
		free (node_contet);
		ft_free_table (&table);
	}
	return (ft_strdup(ftn));
	// return (NULL);
}

void	handle_access_cases(int	error)
{
	perror (PROMPT);
	(void) error;
	exit (127);
}

void	errno_handling(t_minishell *data,int *err, char 	*path)
{
	if (*err == EACCES || *err == EPERM || *err == EFAULT)
	{
		free (path);
		perror("minishell: ");
		exit(126);
	}
	if (*err == ENOENT && !ft_strchr(path, '/'))
	{
		free (path);
		ft_error(data->commands->args[0], COMMAND_NOT_FOUND);
		exit(127);
	}
	free (path);
	perror("minishell: ");
	exit (127);
}
int	exec_smpl_cmnd(t_minishell *data)
{
	char	*path;
	int		fork_res;
	// int 	exec_res;

	path = check_acces (data, data->commands->args[0]);
	fork_res = fork();
	if (fork_res == -1)
		return (perror (PROMPT), -1);
	if (fork_res == 0)
	{
		execve(path, data->commands->args, (data->env));
		errno_handling(data, &errno, path);
	}
	else
	{
		if (waitpid_fnc(data, fork_res) == -1)
			return (-1);
		dprintf(2, "the exit status  is >>>>%d\n", data->exit_s);
		// wait(NULL);
		// ft_free_table(&data->commands); // chech for exit status
		free (path);
	}
	return (data->status);
}
