#include "../../includes/lem_in.h"

void	print_instru(t_lemin *lemin)
{
  t_list 	*tmp_instrus;

  tmp_instrus = lemin->instru;
  while (tmp_instrus)
  {

    ft_printf("%s\n", (char*)tmp_instrus->content);
    tmp_instrus = tmp_instrus->next;
  }
  tmp_instrus = lemin->instru;
  while (tmp_instrus->next)
    tmp_instrus = tmp_instrus->next;
    if (((char**)tmp_instrus->content)[0])
      ft_putchar('\n');
}

t_lemin *init_lem(t_lemin *lemin)
{
  if (!(lemin = (t_lemin*)malloc(sizeof(t_lemin))))
    return (0);
  lemin->instru = NULL;
  lemin->start = 0;
  lemin->end = 0;
  lemin->nb_rooms = 0;
  lemin->nb_link = 0;
  return (lemin);
}

void init_ants(t_ants *a)
{
	a->nbants = 0;
	a->nbstart = 0;
	a->nbend = 0;
}

void del1(void *content, size_t content_size)
{
  (void)content_size;
  if (content)
    free(content);
}
