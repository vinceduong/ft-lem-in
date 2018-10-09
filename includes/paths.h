#ifndef PATH_H
# define PATH_H

# include "lem_in.h"

t_node		*new_node(int nb);
t_nodelist	*add_node(t_nodelist *nodelist, t_node *node);
int		check_nodelist(t_nodelist *nodelist, int nodenb);
t_path		*new_path(t_path *path, int nodenb);
void		*add_path(t_pathlist *pathlist, t_path *path);
t_path		*merge_paths(t_pathlist *paths, t_pathlist *news, t_path *old);
t_path		*delete_path(t_pathlist *paths, t_path *del);
t_nodelist	*cpy_nodelist(t_nodelist *src);
t_path		*init_path(void);
t_pathlist	*init_pathlist(void);
t_nodelist	*init_nodelist(void);
int 		cpy_path(t_path *src, t_path *dest, t_node *node);
t_pathlist		*findpathlist(t_lemin *l, t_pathlist *paths);
void add_new_paths(t_lemin *l, t_pathlist *new_paths, t_path *p);
int		count_new_childs(t_lemin *l, t_path *p);
int 	fill_paths(t_lemin *l, t_pathlist *paths);
t_pathlist		*new_path_list(t_lemin *l, t_pathlist *paths);
void		sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2));
t_pathlist		*update_paths(t_lemin *l, t_pathlist *paths);
int 		paths(t_lemin *l);
void 	delete_used_paths(t_pathlist *paths, t_path *finished, int end);
void		print_path(t_path *path);
void		print_nodelist(t_nodelist *nl);
void 		print_path_list(t_pathlist *pl);
void 			map_dead_nodes(t_lemin *l);
void free_pathlist(t_pathlist *pathlist);


#endif
