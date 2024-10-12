/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:29:10 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 15:29:19 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"


char *expand_var(env_struct *env, const char *var_name) 
{
    char **str;
    int i;
    
    str = env->env;
    i = 0;
    while(str[i] != NULL)
    {
        if (ft_strcmp(str[i], var_name) == 0 && str[i][ft_strlen(var_name)] == '=') 
            return (str[i] + ft_strlen(var_name) + 1);
        i++;
    }
    return NULL;
}