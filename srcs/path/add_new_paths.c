#include "lem_in.h"

t_pathlist	*add_new_paths(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_path *p)
{
	int					i;
	int					new_childs;
	t_pathlist	*new_paths;
	t_node			*new_n;

	i = 0;
	new_childs = 0;
	if (!(new_paths = init_pathlist()))
		return (NULL);
	while (i < l->m.nbcases && ! p->ended)
	{
		if (i && l->m.graph[p->curr][i] && !check_nodelist(bl, i))
		{
			if (!(new_n = new_node(i)))
				return (NULL);
			if (i == l->m.nbcases - 1)
			{
				p->ended = 1;
				add_node(p->nodes, new_n);
				p->nodes->length--;
			}
			else
			{
				add_path(new_paths, new_path(p, i));
				add_node(nl, new_n);
				new_childs++;
			}
		}
		i++;
	}
	return (p->ended ? NULL : (new_childs > 0 ? new_paths : NULL));
}
