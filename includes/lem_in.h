#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

typedef struct		s_lemin
{
	t_map		m;
	t_ants		a;
	t_record	r;
	t_pathlist	p;
	int			nbpaths;
}					t_lemin;

typedef struct		s_map
{
	char	**cases;
	int		end_tunnels;
	int		start_tunnels;
	int		**graph;
	int		nbcases;
}					t_map;

typedef struct		s_ants
{
	int nbants;
	int	nbstart;
	int nbend;
	int **rep;
}					t_ants;

typedef struct		s_record
{
	char	**ops;
	int		nbturns;
}					t_record;

typedef struct		s_pathlist
{
	t_path 	*start;
	int		nbpath;
}					t_pathlist;

typedef struct		s_path
{
	int					curr;
	t_nodelist	nodes;
	int			length;
	t_path		*next;
}					t_path;

typedef struct		s_nodelist
{
	int		length;
	t_node	*start;
}					t_nodelist;

typedef struct		s_node
{
	int		nb;
	int		index;
	t_node	*next;
}					t_node;

/* forme du graph :
   0 1 2 3
0[[0,0,0,0],
1 [0,0,0,0],
2 [0,0,0,0],
3 [0,0,0,0]]*/

/* forme char *case:
["1", "2", "3", "4"]
l'index de la case va definir le numero de la case dans int **case;
*/

/* forme int **rep :
[[1,2,3,4], [5,6,7,8]]
/* forme **ops :
["L1-2", "L1-3 L2-2", "L1-1 L2-3 L3-2"]
*/

//On initialise map ants, si la map est invalide => return 0
int	parse(t_lemin *lemin);
//On cherche les plus courts chemins, si on trouve aucun path => return 0;
int	path(t_lemin *lemin);
//On reparti les chemins pour les fourmis, on rempli ants->rep;
int	split_ants(t_lemin *lemin);
//On record les tours en faisant avancer les fourmis sur chaque path;
int	record(t_lemin *lemin);
//On affiche les tours sur l'entrée standard
int	display(t_lemin *lemin);

//NODELIST FUNCTIONS
t_node			*new_node(int nb);
t_nodelist	*add_node(t_nodelist *nodelist, t_node *node);
int					check_nodelist(t_nodelist *nodelist, int nodenb);

#endif
