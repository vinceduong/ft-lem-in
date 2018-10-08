#include "lem_in.h"

void	add_new_paths(t_lemin *l, t_pathlist *new_paths, t_path *p)
{
	int					i;
	int					new_childs;
	t_node			*new_n;
	t_path			*new_p;

	ft_putstr("In add_new_paths\n");
	i = 0;
	new_childs = 0;
	if (p->ended)
	{
		ft_putstr("Path already ended\n");
		add_path(new_paths, new_path(p, -1));
		ft_putstr("Path added\n");
	}
	while (i < l->m.nbcases && !p->ended)
	{
		if (l->m.graph[p->curr][i] && l->m.graph[i][i] != 1 && l->m.graph[i][i] != -1)
		{
			printf("Curr = %d, Unused child = %d found\n", p->curr, i);
 			if (!(new_n = new_node(i)))
				return ;
			ft_putstr("Node created\n");
			new_p = new_path(p, i);
			add_path(new_paths, new_p);
			if (i == l->m.nbcases - 1)
			{
				new_p->ended = 1;
				//delete_used_paths(new_paths, new_p, i);
				print_path_list(new_paths);
				ft_putstr("Path ended\n");
			}
			else
			{
				ft_putstr("New path created\n");
				l->m.graph[i][i] = 1;
			}
			new_childs++;
		}
		i++;
	}
}
