#include "lem_in.h"

void free_cases(int **cases, int nb)
{
	int i;

	if (cases)
	{
		i = 0;
		while (i < nb)
		{
			if (cases[i])
				free(cases[i]);
			i++;
		}
	}
}
