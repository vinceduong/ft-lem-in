#include "lem_in.h"

void		*add_path(t_pathlist *pathlist, t_path *path)
{
	t_path	*tmp;

	tmp = pathlist->start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = path;
	path->previous = tmp;
	return (pathlist);
}
