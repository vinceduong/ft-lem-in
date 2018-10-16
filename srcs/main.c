#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	if (!parser(&lemin))
		return (0);
<<<<<<< HEAD
	}
	ft_printf("Parsing worked\n");
=======
>>>>>>> 2d449dccefd7d84a3aae5b20502d32cfe06db5a4
	if (!paths(&lemin))
		return (0);
<<<<<<< HEAD
	}
	ft_printf("Pathing worked\n");
	int i = 0;
	while (i < lemin.nbpaths)
	{
		//print_path(&lemin.p[i]);
		i++;
	}
=======
>>>>>>> 2d449dccefd7d84a3aae5b20502d32cfe06db5a4
	if (!split_ants(&lemin))
		return (0);
<<<<<<< HEAD
	}
	ft_printf("Split ants worked\n");
=======
>>>>>>> 2d449dccefd7d84a3aae5b20502d32cfe06db5a4
	if (!record(&lemin))
		return (0);
<<<<<<< HEAD
	}
	ft_printf("Record worked\n");
=======
>>>>>>> 2d449dccefd7d84a3aae5b20502d32cfe06db5a4
	if (!display(&lemin))
		return (0);
<<<<<<< HEAD
	}
=======
>>>>>>> 2d449dccefd7d84a3aae5b20502d32cfe06db5a4
	return (0);
}
