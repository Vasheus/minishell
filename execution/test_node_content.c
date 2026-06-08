#include "includes/minishell.h"

void	test_node_content(t_minishell *data)
{
	set_args *args;

	int i =0;
	args = data->commands;
	while (args)
	{
		puts("%%%%%%%%%%%%%%%%%%%%%%%    the args\n");
		printf("the input is >%d\n",args->input);
		printf("the output is >%d\n",args->output);
		puts("######################## the args\n");
		i=0;
		while (args->args[i])
		{
			printf("## TEH ARGS ARE>%s\n",args->args[i]);
			i++;
		}
		args = args->next;
	}
}
void	test_list_content(t_minishell *data)
{
	t_list *list;
	list = data->list;
	while (list)
	{
		puts("&&&&&&&&&&&&&&&&&&&&&&&      the list\n");
		printf("the content is %s\n",list->content);
		printf("the type is %u\n",list->type);
		printf("the command is %u\n",list->command);
		puts("&&&&&&&&&&&&&&&&&&&&&&&\n");
		list = list->next;
	}
}