#include "lem_in.h"

void		print_path(t_path *path)
{
		printf("----------\n");
		printf("ENDED = %d\n", path->ended);
		printf("CURR = %d\n", path->curr);
		printf("NCHILDS = %d\n", path->childs);
		printf("NODES = ");
		print_nodelist(path->nodes);
		printf("----------\n");
}

void print_nodelist(t_nodelist *nl)
{
	t_node *tmp;

	tmp = nl->start;
	while(tmp)
	{
		if (tmp->next)
			printf("%d->", tmp->nb);
		else
			printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}
