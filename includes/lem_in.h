#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdio.h>
# include "paths.h"

typedef struct		s_node
{
	int					nb;
	int					index;
	struct s_node		*next;
}					t_node;

typedef struct		s_nodelist
{
	int		length;
	t_node	*start;
}					t_nodelist;

typedef struct		s_path
{
	int					curr;
	int					childs;
	t_nodelist			*nodes;
	int					ended;
	struct s_path		*next;
	struct s_path		*previous;
}					t_path;

typedef struct		s_pathlist
{
	t_path		*start;
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
	t_map			m;
	t_ants			a;
	t_record		r;
	t_path			*p;
	int				nbpaths;
	t_list			*instru;
	int				start;
	int				end;
	int				nb_rooms;
	int				nb_link;
}					t_lemin;

int					ft_check_room(char **tab, int i);
void				print_ant_road(t_lemin *lemin);
int					parser(t_lemin *lemin);
int					paths(t_lemin *lemin);
int					split_ants(t_lemin *lemin);
int					record(t_lemin *lemin);
int					display(t_lemin *lemin);
int					ft_patatruc(char **tab, t_lemin *lemin, int *error_tab);
int					ft_matrice(char **tab, t_lemin *l, int *t, int i);
int					ft_chrstr(char *find, int c);
int					ft_intlen(int nb);
int					ft_coord_is_digit(char *str);
void				ft_get_length(t_lemin *lemin);
void				ft_clean(char **tab);
t_node				*new_node(int nb);
t_nodelist			*add_node(t_nodelist *nodelist, t_node *node);
int					check_nodelist(t_nodelist *nodelist, int nodenb);
t_path				*new_path(t_path *path, int nodenb);
void				*add_path(t_pathlist *pathlist, t_path *path);
t_path				*delete_path(t_pathlist *paths, t_path *del);
t_nodelist			*cpy_nodelist(t_nodelist *src, t_nodelist *dest);
t_path				*init_path(void);
t_pathlist			*init_pathlist(void);
t_nodelist			*init_nodelist(void);
int					cpy_path(t_path *src, t_path *dest, t_node *node);
t_pathlist			*findpathlist(t_lemin *l, t_pathlist *paths);
void				add_new_paths(t_lemin *l, t_pathlist *new_paths, t_path *p);
int					count_new_childs(t_lemin *l, t_path *p);
int					fill_paths(t_lemin *l, t_pathlist *paths);
t_pathlist			*new_path_list(t_lemin *l, t_pathlist *paths);
void				sort_paths(t_pathlist *p, int (*c)(t_path *p1, t_path *p2));
t_pathlist			*update_paths(t_lemin *l, t_pathlist *paths);
int					paths(t_lemin *l);
void				delete_used_paths(t_pathlist *p, t_path *f, int e);
void				print_path(t_path *path);
void				print_nodelist(t_nodelist *nl);
void				print_path_list(t_pathlist *pl);
void				map_dead_nodes(t_lemin *l);
void				free_path(t_path *path);
void				free_pathlist(t_pathlist *pathlist);
void				free_nodelist(t_nodelist *nodelist);
void				free_node(t_node *node);
t_pathlist			*find_pathlist(t_lemin *l, t_pathlist *paths);
void				ft_free_int(int **tab, int size);
int					*ft_create_error_tab(void);
int					ft_check_value_2(t_lemin *lemin, int *error_tab);

#endif
