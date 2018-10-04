#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_node
{
	int		nb;
	int		index;
	struct s_node	*next;
}					t_node;

typedef struct		s_nodelist
{
	int		length;
	t_node	*start;
}					t_nodelist;

typedef struct		s_path
{
	int 				curr;
	int					childs;
	t_nodelist	*nodes;
	int					ended;
	struct s_path			*next;
	struct s_path			*previous;
}					t_path;

typedef struct		s_pathlist
{
	t_path 	*start;
}					t_pathlist;

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
	int **rep;
}					t_ants;

typedef struct		s_record
{
	char	**ops;
	int		nbturns;
}					t_record;

typedef struct		s_lemin
{
	t_map		m;
	t_ants		a;
	t_record	r;
	t_path	*p;
	int			nbpaths;
	t_list		*instru;
	int 			start;
	int 			end;
	int 			nb_rooms;
	int 			nb_link;
}					t_lemin;

# include "paths.h"
/* forme du graph :
   0 1 2 3
0[[0,0,0,0],
1 [0,0,0,0],
2 [0,0,0,0],
3 [0,0,0,0]]*/

void print_matrix(t_lemin *l);
//On initialise map ants, si la map est invalide => return 0
int	parser(t_lemin *lemin);
//On cherche les plus courts chemins, si on trouve aucun path => return 0;
int	paths(t_lemin *lemin);
//On reparti les chemins pour les fourmis, on rempli ants->rep;
int	split_ants(t_lemin *lemin);
//On record les tours en faisant avancer les fourmis sur chaque path;
int	record(t_lemin *lemin);
//On affiche les tours sur l'entrée standard
int	display(t_lemin *lemin);

//foncitons de Cam
void ft_patatruc(char **tab, t_lemin *lemin);
void ft_create_matrice(char **tab, t_lemin *lemin, int **error_tab);
int		ft_chrstr(char *find, int c);
int ft_check_value(int **error_tab);

#endif
