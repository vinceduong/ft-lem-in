#include "lem_in.h"

int		compare_length(t_path *p1, t_path *p2)
{
	return (p1->nodes->length > p2->nodes->length);
}

void	sort_paths_array(t_path **array, int size)
{
	int		i;
	t_path	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (compare_length(array[i], array[i + 1]))
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

void	fill_array(t_lemin *l, t_pathlist *paths, t_path **array)
{
	int		i;
	t_path	*tmp;

	tmp = paths->start;
	i = 0;
	while (tmp)
	{
		if (tmp->ended)
		{
			array[i] = new_path(tmp, -1);
			i++;
		}
		tmp = tmp->next;
	}
	l->nbpaths = i;
	sort_paths_array(array, i);
}

int		fill_paths(t_lemin *l, t_pathlist *paths)
{
	t_path	*tmp;
	t_path	**array;
	int		size;

	size = 0;
	tmp = paths->start;
	while (tmp)
	{
		if (tmp->ended)
			size++;
		tmp = tmp->next;
	}
	if (!(array = (t_path **)malloc(sizeof(t_path *) * size)))
		return (0);
	fill_array(l, paths, array);
	l->p = array;
	free_pathlist(paths);
	return (1);
}
