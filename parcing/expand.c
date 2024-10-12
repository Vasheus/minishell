/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:29:10 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/12 15:58:29 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

char *get_var_value(char *str)
{
    char *var_name;
    char *value;
    
    var_name = str + 1;
    value = getenv(var_name);
    
    if(value)
        return(value);
    else
        return("");
}