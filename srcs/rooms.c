#include "../includes/lem_in.h"

static char **creat_tab(char *line, char **tab)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;

    while (*line)
    {
        while (line[len] && line[len] != ' ')
            len++;
        if (!(tab[i] = (char*)malloc(len * sizeof(char))))
            return (0);
        while (line[i] && line[i] != ' ')
            tab[i][j++] = *(line++);
        tab[i][j] = '\0';
        j = 0;
        len = 0;
        i++;
        line++;
    }
	return (tab);
}

static char **parsetab(t_lemin *lemin, char *line)
{
	char **tab;

	if (!(tab = (char**)malloc(3 * sizeof(char*))))
		return (0);
	if (line)
		return (creat_tab(line, tab));
	else
		return (NULL);
}

int readrooms(t_lemin *lemin, char *line)
{
		char **tb;

		if (!(lemin->m.cases = (char**)malloc(3 * sizeof(char*))))
		if (!(tb = (char**)malloc(3 * sizeof(char*))))
		return (0);
		if (!(tb = parsetab(lemin, line)))
			return (0);
    lemin->m.cases = tb;
		return (1);
}
