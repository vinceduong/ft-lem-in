#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_lemin
{
	s_map			m;
	s_paths		*p;
	s_ants		a;
	s_record	r;
}								t_lemin;

typedef struct	s_ants
{
	int nbants;
	int	nbstart;
	int nbend;
	int **rep;
}								t_ants;

typedef struct	s_record
{
	char	**ops;
	int		nbturns;
}								t_record;

typedef struct	s_path
{
		int		**cases;
		int		length;
}								t_op;

typedef struct	s_map
{
	char		*cases;
	int			end_tunnels;
	int			start_tunnels;
	int			**graph;
}								t_map;

//On initialise map ants, si la map est invalide => return 0
int	parse(t_lemin lemin);
//On cherche les plus courts chemins, si on trouve aucun path => return 0;
int	path(t_lemin lemin);
//On reparti les chemins pour les fourmis, on rempli ants->rep;
int	split_ants(t_lemin lemin);
//On record les tours en faisant avancer les fourmis sur chaque path;
int	record(t_lemin lemin);
//On affiche les tours sur l'entrée standard
int	display(t_lemin lemin);


#endif
