#include "lem_in.h"

int *init_check(nb)
{
	int *check;
	int i;

	if (!(check = (int *)malloc(nb * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		check[i] = 0;
		i++;
	}
	return (check);
}

int *cpy_check(int *check, int nb)
{
	int *new;

	if (!(new = (int *)malloc(nb * sizeof(int))))
		return (NULL);
	while (i < nb)
	{
		new[i] = check[i];
		i++;
	}
	return (check);
}

int add_case(t_path *path, int case)
{
	int	**cases;
	int	i;

	i = 0;
	if (!(cases = (int **)malloc((path->length + 1) * sizeof(int *))))
		return (0);
	while (i < path->length + 1)
	{
		if (!(cases[i] = (int *)malloc(2 * sizeof(int))))
			return (0);
		if (i != path->length)
		{
			cases[i][0] = path->cases[i][0];
			cases[i][1] = 0;
		}
		else
		{
			cases[i][0] = case;
			cases[i][1] = 0;
		}
		i++;
	}
	free_cases(path->cases);
	path->cases = cases;
	return (1);
}
