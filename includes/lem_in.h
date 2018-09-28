#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct	s_lemin
{
	int			nbant;
}				t_lemin;

typedef struct	s_ants
{
	int nbants;
	int	nbstart;
	int nbend;
	int **rep;
}								t_ants;

typedef struct	s_record
{
	char	*ops;
	int		nbturns;
}								t_record;

typedef struct	s_path
{
		int		*cases;
		int		length;
}								t_op;

typedef struct	s_map
{
	char		*cases;
	int			**graph;
	t_path	*paths;
	s_ants	ants;
}								t_map;

#endif
