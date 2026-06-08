/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:38:27 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/12 18:44:40 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int small_parse(t_minishell *data, char *cmd)
{
	if(!ft_strncmp(cmd, "export",(ft_strlen(cmd)+1)) ||
	  !ft_strncmp(cmd, "cd",(ft_strlen(cmd)+1)) ||
	  !ft_strncmp(cmd, "exit",(ft_strlen(cmd)+1)) ||
	  !ft_strncmp(cmd, "env",(ft_strlen(cmd)+1)) ||
	  !ft_strncmp(cmd, "unset",(ft_strlen(cmd)+1)) ||
	  !ft_strncmp(cmd, "echo",(ft_strlen(cmd)+1)))
		data->list->type = BUILT_IN;
	// else if (cmd[0] == '/' || !ft_strncmp(cmd, "./",2))
	else
		data->list->type = SIMPLE_COMMAND;
		// ft_error(data->args[0], (t_tags)COMMAND_NOT_FOUND);
	return (0);
}
