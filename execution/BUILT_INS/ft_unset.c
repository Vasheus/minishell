/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:27:22 by ael-garr          #+#    #+#             */
/*   Updated: 2024/10/18 22:36:50 by ael-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unset(t_minishell *data)
{
	t_environ	*local;
	t_environ	*prev;
	int			i;

	i = 1;
	while (i < count_table_entries(data->commands->args))
	{
		if (check_syntax_for_export (data->commands->args[i]))
		{
			local = data->env_lst;
			prev = NULL;
			while (local)
			{
				if (ft_strncmp(local->var, data->commands->args[i], ft_strlen(local->var) + 1) == 0)
				{
					free(local->value);
					free(local->var);
					if (prev)
						prev->next = local->next;
					else
						data->env_lst = local->next;
					free(local);
					local = prev ? prev->next : data->env_lst; // Move to the next node
				}
				else
				{
					prev = local;
					local = local->next;
				}
			}
		}
		else
			ft_error_export_2_args(data->commands->args[0],	data->commands->args[i]);
		i++;
	}
	return (0);
}
