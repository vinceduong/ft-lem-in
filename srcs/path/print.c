#include "lem_in.h"

void		print_path(t_path *path)
{
		printf("----------\n");
		printf("ENDED = %d\n", path->ended);
		printf("CURR = %d\n", path->curr);
		printf("NCHILDS = %d\n", path->childs);
		printf("LENGTH = %d\n", path->nodes->length);
		printf("ADRESS    = %p\n", path);
		printf("NEXT      = %p\n", path->next);
		printf("PREVIOUS  = %p\n", path->previous);
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

void print_path_list(t_pathlist *pl)
{
	t_path *tmp;
	int i;

	i  = 0;
	tmp = pl->start;
	printf("-------------PATHLIST------------\n");
	while (tmp)
	{
		printf("Path %d :\n", i);
		i++;
		print_path(tmp);
		tmp = tmp->next;
	}
	printf("-------------END PATHlIST------------\n");
}
