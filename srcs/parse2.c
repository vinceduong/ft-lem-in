#include "../includes/lem_in.h"


static int check_start_end(t_lemin *lemin, char *line)
{
  lemin->start = NULL;
  lemin->end = NULL;
if (line)
{
  if (!ft_strcmp("##start", line))
  {
    //printf("line = %s\n", line);
    get_next_line(0, &line);
    lemin->start = line;
    printf("line1 = %s\n", line);
    printf("start = %s\n", lemin->start);

    //printf("line1 = %s\n", line);
  }
  if (!ft_strcmp("##end", line))
  {
    get_next_line(0, &line);
    lemin->end = line;
    printf("line2 = %s\n", line);
    printf("end = %s\n", lemin->end);
    //if (!ft_strchr(line, ' ')) //|| ft_strchr(line, '-'))
      //return (0);
  //  printf("line2 = %s\n", line);
}
}
  return (1);
}

int read2(t_lemin *lemin, char *line)
{
  if (line)
  {
    if (line[0] == '#' && line[1] == '#')
    {
      if (!(check_start_end(lemin, line)))
        return (0);
    }
  }
  else
    return (0);
  return (1);
}
