/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdeocfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:11:29 by yosabir           #+#    #+#             */
/*   Updated: 2024/10/10 14:44:23 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

static void generate_temp_filename(char *buffer, int index) 
{
    char *index_str;
	
	index_str = ft_itoa(index);
    if (index_str)
	{
        ft_strlcpy(buffer, "/tmp/", 256);
        ft_strlcat(buffer, "heredoc_", 256);
        ft_strlcat(buffer, index_str, 256);
        ft_strlcat(buffer, ".txt", 256);
        free(index_str);
    }
}

int create_unique_heredoc_file() 
{
    char filename[256];
    int index;
    int fd;
	
	index = 1;
    while (1) 
	{
        generate_temp_filename(filename, index);
        fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, 644);
        if (fd != -1)
            break;
        index++;
    }

    return fd;
}

