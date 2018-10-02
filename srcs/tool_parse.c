#include "../includes/lem_in.h"

void	print_instru(t_lemin *lemin)
{
  t_list 	*tmp_instrus;

  tmp_instrus = lemin->instru;
  while (tmp_instrus)
  {

    printf("%s\n", (char*)tmp_instrus->content);
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
  lemin->start = NULL;
  lemin->end = NULL;
  lemin->links = NULL;
  return (lemin);
}

void del1(void *content, size_t content_size)
{
  (void)content_size;
  if (content)
    free(content);
}
