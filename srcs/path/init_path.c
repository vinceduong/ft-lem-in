#include "lem_in.h"

t_path *init_path(void)
{
	t_path *p;

	if (!(p = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	p->curr = 0;
	p->childs = 0;
	if (!(p->nodes = init_nodelist()))
		return (NULL);
	p->ended = 0;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}

t_pathlist *init_pathlist()
{
	t_pathlist *pl;

	if (!(pl = (t_pathlist *)malloc(sizeof(t_pathlist))))
		return (NULL);
	pl->start = NULL;
	return (pl);
}

t_path		*new_path(t_path *path, int nodenb)
{
	t_path			*new;
	t_node			*node;
	t_nodelist 	*nl;

	ft_putstr("In new_path\n");
	if (!(node = new_node(nodenb)))
	{
		ft_putstr("new_node failed\n");
		return (NULL);
	}
	if (!(new = init_path()))
	{
		ft_putstr("init_path failed\n");
		return (NULL);
	}
	if (!(nl = init_nodelist()))
	{
		ft_putstr("init_path failed\n");
		return (NULL);
	}
	if (!path)
	{
			ft_putstr("In if !path\n");
			new->curr = nodenb;
			ft_printf("node->nb = %d", node->nb);
			add_node(nl, node);
			ft_putstr("add_node worked\n");
			new->nodes = nl;
			new->ended = 0;
	}
	else
		cpy_path(path, new, node);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
