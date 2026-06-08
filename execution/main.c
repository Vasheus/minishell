/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:46:08 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/24 20:17:09 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// extern int g_signal;


int exec(t_minishell *data)
{
	int result;
	
	result = 0;
	if (data->list->type == BUILT_IN /*&& ft_lstsize_m(data->list) == 1*/)
		result = start_execution(data);
	else if (ft_lstsize_c(data->commands) == 1  && data->list->type == SIMPLE_COMMAND)
		result = exec_smpl_cmnd(data);
	else if (ft_lstsize_c(data->commands) >= 2)
		result = multi_commands(data);
	// ft_free_table(&data->commands);
	// ft_free_table(&data->args);
	// if (result == -1)
		// return(ft_err_msg((t_error){COMMAND_NOT_FOUND,ENO_CMMND_NT_FOND,data->args[0]}), -1);
	return (result);
}

void f(){
	system("leaks minishell");
}
int main(int 	argc, char **argv, char **env)
{
	// atexit(f);
	(void)argc;
	(void)argv;
	t_minishell data;
	// t_list *lst;
	// lst = data.list;
	data.env = env;
	data.env_lst = create_list(&data);
	rl_catch_signals = 0;
	init_signl();
	while (1)
	{
		data.line = readline(PROMPT);   //TO_FREE 
		if (!data.line)
			break ;
		if (data.line && data.line[0])
		{
			// exit(9);
			add_history(data.line);
			// small_parse(&data, data.args[0]);
			data.list = parsing(data.line);
        	if (syntax(&data.list) == 1)
				continue ;
        	classing(&data.list);
			data.commands = settingargs(&data.list);
			// test_list_content(&data);
			g_signal = 1;
			data.exit_s = exec(&data);       //####### the executioon function
			g_signal = 0;
		}
		// clear_history();
	}
	return(0);
}

int start_execution(t_minishell *data)
{
	// int result;
	// if (!data->list)
	// 	return (-1);
	if (!ft_strncmp(data->list->content,"cd",3))
		data->exit_s = ft_cd(data);
	else if (!ft_strncmp(data->list->content,"pwd",4))
		data->exit_s = ft_pwd(data);
	else if (!ft_strncmp(data->list->content, "echo", 5))
		ft_echo(data);
	else if (!ft_strncmp(data->list->content, "export", 7))	
		ft_export(data);
	else if (!ft_strncmp(data->list->content, "env", 4))
		ft_env(data);
	else if (!ft_strncmp(data->list->content, "exit", 5))
		ft_exit(data);
	else if (!ft_strncmp(data->list->content, "unset", 6))
		ft_unset(data);
	// else 
	// 	ft_err_msg((t_error){COMMAND_NOT_FOUND,ENO_CMMND_NT_FOND,data->args[0]});
	return (-1);
	// free(data->old_path);
}
