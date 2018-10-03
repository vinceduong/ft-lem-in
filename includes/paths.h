#ifndef PATH_H
# define PATH_H

# include "lem_in.h"

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
int cpy_path(t_path *src, t_path *dest, t_node *node);
int findpathlist(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths);
t_pathlist	*add_new_paths(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_path *p);
int	count_new_childs(t_lemin *l, t_nodelist *nl, t_path *p);
t_path *list_to_sorted_array(t_pathlist *paths);
int new_path_list(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths);
void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2));
int	update_paths(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths);
int 	paths(t_lemin *l);

void ft_patatruc(char **tab, t_lemin *lemin);
void ft_create_matrice(char **tab, t_lemin *lemin, int **error);
int		ft_chrstr(char *find, int c);

#endif
