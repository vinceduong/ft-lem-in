#include "lem_in.h"

void	add_new_paths(t_lemin *l, t_pathlist *new_paths, t_path *p)
{
	int		i;
	int		new_childs;
	t_path	*new_p;

	i = 0;
	new_childs = 0;
	if (p->ended)
	{
		new_p = new_path(p, -1);
		add_path(new_paths, new_p);
	}
	while (i < l->m.nbcases && !p->ended)
	{
		if (l->m.graph[p->curr][i] && l->m.graph[i][i] == 0)
		{
			new_p = new_path(p, i);
			add_path(new_paths, new_p);
			if (i == l->m.nbcases - 1)
				new_p->ended = 1;
			else
				l->m.graph[i][i] = 1;
			new_childs++;
		}
		i++;
	}
}
