#include "lem_in.h"

void		*add_path(t_pathlist *pathlist, t_path *path)
{
	t_path	*tmp;

	tmp = pathlist->start;
	if (!tmp)
	{
		pathlist->start = path;
		return (pathlist);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = path;
	path->previous = tmp;
	return (pathlist);
}
