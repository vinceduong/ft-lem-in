#include "lem_in.h"

t_pathlist	*add_new_paths(t_lemin *l, t_path *p)
{
	int					i;
	int					new_childs;
	t_pathlist	*new_paths;
	t_node			*new_n;
	t_path			*new_p;

	ft_putstr("In add_new_paths\n");
	i = 0;
	new_childs = 0;
	if (!(new_paths = init_pathlist()))
		return (NULL);
	while (i < l->m.nbcases && ! p->ended)
	{
		if (l->m.graph[p->curr][i] && !l->m.graph[i][i])
		{
			ft_putstr("Unused node found\n");
 			if (!(new_n = new_node(i)))
				return (NULL);
			ft_putstr("Node created\n");
			if (i == l->m.nbcases - 1)
			{
				ft_putstr("Path ended\n");
				p->ended = 1;
				add_node(p->nodes, new_n);
				p->curr = i;
				p->nodes->length--;
			}
			else
			{
				new_p = new_path(p, i);
				ft_putstr("New path created\n");
				add_path(new_paths, new_p);
				l->m.graph[i][i] = 1;
				print_matrix(l);
				print_path(new_p);
				new_childs++;
			}
		}
		i++;
	}
	return (p->ended ? NULL : (new_childs > 0 ? new_paths : NULL));
}
