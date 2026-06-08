/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:29:24 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/12 18:42:37 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	echo_local(t_minishell *data)
// {
// 	while (/* condition */)
// 	{
// 		/* code */
// 	}
	
// }


int ft_echo(t_minishell *data)
{
	char **local;
	local = &(data->commands->args[1]);
	if (!local || !local)
		return(-1);
	while (local && *local)
	{
		// if (!write(1, NULL,0))
		// 	return(-1);
		ft_putstr_fd(*local, 1);
		ft_putstr_fd(" ", 1);
		local++;
		// exit(8);
	}
	ft_putstr_fd("\n",1);
	return(0);
	// if (data->env[1] && data->env[1][0])
		// echo_local(data);


}