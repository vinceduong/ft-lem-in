#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct	s_lemin
{
	int			nbant;
}				t_lemin;

typedef struct s_record
{
	char	*ops;
	int		nbturns;
}

typedef struct	s_path
{
		int		*cases;
		int		length;
}								t_op;

typedef struct	s_map
{
	int			nbants;
	int			nbstart;
	int			nbend;
	int			**graph;
	t_path	*paths;
}								t_map;

#endif
