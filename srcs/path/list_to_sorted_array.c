#include "lem_in.h"

t_path *list_to_sorted_array(t_pathlist *paths)
{
	t_path	*tmp;
	t_path	*array;
	int			size;
	int			i;

	size = 0;
	tmp = paths->start;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (!(array = (t_path *)malloc(sizeof(t_path) * size)))
		return (NULL);
	sort_paths(paths, &compare_length);
	tmp = paths->start;
	i = 0;
	while (tmp)
	{
		array[i] = *tmp;
		i++;
		tmp = tmp->next;
	}
	return (array);
}
