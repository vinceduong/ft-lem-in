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

int	main(void)
{
	t_lemin lemin;

	ft_bzero(&lemin, 0);
	if (!parse(&lemin))
	{
		printf("Parsing failed");
		printf("ERROR");
	}
	/*if (!path(lemin))
	{
		printf("Pathing failed");
		printf("ERROR");
	}
	if (!split_ants(lemin))
	{
		printf("Splitting failed");
		printf("ERROR");
	}
	if (!record(lemin))
	{
		printf("Recording failed");
		printf("ERROR");
	}
	if (!display(lemin))
	{
		printf("Display failed");
		printf("ERROR");
	}*/
	return (0);
}
