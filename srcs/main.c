#include "../includes/lem_in.h"

void	print_instru(t_lemin *lemin)
{
  t_list 	*tmp_instrus;

  tmp_instrus = lemin->instru;
  printf("\nINSTRU -><- -><- \n");
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
  return (lemin);
}

int	main(void)
{
	t_lemin lemin;

	if (!parse(&lemin))
	{
		printf("Parsing failed\n");
		printf("ERROR");
	}
	/*if (!path(lemin))
	{
		ft_printf("Pathing failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!split_ants(&lemin))
	{
		ft_printf("Splitting failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!record(&lemin))
	{
		ft_printf("Recording failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!display(&lemin))
	{
		printf("Display failed");
		printf("ERROR");
	}*/
	return (0);
}
