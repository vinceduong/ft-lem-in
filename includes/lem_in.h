#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "error.h"
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
	int	nbstart;
	int nbend;
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
	t_pathlist	*p;
	int			nbpaths;
}					t_lemin;

/* forme du graph :
   0 1 2 3
0[[0,0,0,0],
1 [0,0,0,0],
2 [0,0,0,0],
3 [0,0,0,0]]*/

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
t_path		*new_path(t_path *path, int nodenb);
void		*add_path(t_pathlist *pathlist, t_path *path);
t_path *merge_paths(t_pathlist *paths, t_pathlist *news, t_path *old);
t_path *delete_path(t_pathlist *paths, t_path *del);
void					update_bl(t_nodelist *bl, t_path *path);
t_nodelist *cpy_nodelist(t_nodelist *src);
t_path *init_path(void);
t_pathlist *init_pathlist(void);
t_nodelist *init_nodelist(void);

#endif
