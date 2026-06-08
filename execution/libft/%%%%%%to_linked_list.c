#include "../includes/minishell.h"

t_environ	*create_list(t_minishell	*data)
{
	char		**table;
	char		*name;
	char		*value;
	t_environ	*lst = NULL;
	int			i = 0;
	int			j;
	int			x;

	table = data->env;
	if (!table[i] && !table[i][0])
		return(NULL);
	while (table[i])
	{
		name = malloc(to_alloc(table[i], '='));
		value = malloc(to_alloc(ft_strchr(table[i],'='),'\0'));
		j = 0;
		x= 0;
		while (table[i][j] && table[i][j] != '=')
			name[x++] = table[i][j++];
		name[x] = '\0';
		x = 0;
		if (table[i][j] == '=')
			j++;
		while (table[i][j])
			value[x++] = table[i][j++];
		value[x] = '\0';
		ft_lstadd_back_env(&lst, ft_lstnew_env((name), (value)));     // TO_FREE TO_FREE TO_FREE
		i++;
	}
	return (lst);
}
