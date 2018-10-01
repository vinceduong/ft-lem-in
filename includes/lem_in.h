#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>

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

typedef struct	s_paths
{
		int		**cases;
		int		length;
}								t_paths;

typedef struct	s_map
{
	char		**cases;
	int			end_tunnels;
	int			start_tunnels;
	int			**graph;
	int 		nbcases;
}								t_map;

typedef struct	s_lemin
{
	t_map			m;
	t_paths		*p;
	t_ants		a;
	t_record	r;
	t_list		*instru;
}								t_lemin;

t_lemin *init_lem(t_lemin *lemin);
void	print_instru(t_lemin *lemin);
int readrooms(t_lemin *lemin, char *line);
/* forme du graph :
   0 1 2 3
0[[0,0,0,0],
1 [0,0,0,0],
2 [0,0,0,0],
3 [0,0,0,0]]*/

/* forme char **case:
["1", "2", "3", "4"]
l'index de la case va definir le numero de la case dans int **case;
*/

/* forme int **case :
[[0,0], [1,0], [2,0], [3,0]], [numero la case, fourmi l'occupant]
*/

/* forme int **rep :
[[1,2,3,4], [5,6,7,8]]
 forme **ops :
["L1-2", "L1-3 L2-2", "L1-1 L2-3 L3-2"]
*/

//On initialise map ants, si la map est invalide => return 0
int	parse(t_lemin *lemin);
//On cherche les plus courts chemins, si on trouve aucun path => return 0;
int	path(t_lemin lemin);
//On reparti les chemins pour les fourmis, on rempli ants->rep;
int	split_ants(t_lemin lemin);
//On record les tours en faisant avancer les fourmis sur chaque path;
int	record(t_lemin lemin);
//On affiche les tours sur l'entrée standard
int	display(t_lemin lemin);


#endif
