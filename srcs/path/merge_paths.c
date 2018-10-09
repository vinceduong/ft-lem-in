#include "lem_in.h"

t_path *merge_paths(t_pathlist *paths, t_pathlist *news, t_path *old)
{
	t_path *tmp_list;
	t_path *tmp_new;

	tmp_list = paths->start;
	tmp_new = news->start;
	if (tmp_list == old)
		paths->start = news->start;
	else
	{
		while (tmp_list->next && tmp_list->next != old)
			tmp_list = tmp_list->next;
		tmp_list->next = tmp_new;
	}
	while (tmp_new->next)
		tmp_new = tmp_new->next;
	tmp_new->next = old->next;
	tmp_new->previous = tmp_list == old ? NULL : tmp_list;
	return (tmp_new->next);
}
