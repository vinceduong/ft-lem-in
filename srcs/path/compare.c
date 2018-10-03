#include "lem_in.h"

int compare_childs(t_path *p1, t_path *p2)
{
	return (p1->childs > p2->childs);
}

int compare_length(t_path *p1, t_path *p2)
{
	return (p1->nodes->length > p2->nodes->length);
}
