#include "lem_in.h"

int compare_length(t_path *p1, t_path *p2)
{
	return (p1->nodes->length > p2->nodes->length);
}

int fill_paths(t_lemin *l, t_pathlist *paths)
{
	t_path	*tmp;
	t_path	*array;
	int			size;
	int			i;

	size = 0;
	tmp = paths->start;
	if (!tmp)
		return (0);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (!(array = (t_path *)malloc(sizeof(t_path) * size)))
		return (0);
	sort_paths(paths, &compare_length);
	tmp = paths->start;
	i = 0;
	while (tmp)
	{
		array[i] = *tmp;
		i++;
		tmp = tmp->next;
	}
	l->nbpaths = i;
	l->p = array;
	return (1);
}
