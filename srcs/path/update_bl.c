#include "lem_in.h"

void					update_bl(t_nodelist *bl, t_path *path)
{
	t_node *tmp;

	tmp = path->nodes->start;
	while (tmp)
	{
		if (!check_nodelist(bl, tmp->nb))
		{
			add_node(bl, new_node(tmp->nb));
			return ;
		}
		tmp = tmp->next;
	}
}
