#include "lem_in.h"

int	compare_length(t_path *p1, t_path *p2)
{
	return (p1->nodes->length > p2->nodes->length);
}

void	sort_paths_array(t_path *array, int size)
{
	int		i;
	t_path	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (compare_length(&array[i], &array[i + 1]))
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	fill_paths(t_lemin *l, t_pathlist *paths)
{
	t_path	*tmp;
	t_path	*array;
	int		size;

	size = 0;
	tmp = paths->start;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (!(array = (t_path *)malloc(sizeof(t_path) * size)))
		return (0);
	tmp = paths->start;
	size = 0;
	while (tmp)
	{
		array[size++] = *tmp;
		tmp = tmp->next;
	}
	l->nbpaths = size;
	sort_paths_array(array, size);
	l->p = array;
	free(paths);
	return (1);
}
