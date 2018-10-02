#include "../../includes/lem_in.h"

int 	checkrooms(char **tab, char *line)
{
	int n;
	int i;
	int j;

	i = 0;
	j = 0;
	n = 0;
	while (*line)
	{
		while (*(line + n) && *(line + n) != ' ')
			n++;
		if (!(tab[i] = (char*)malloc(n * sizeof(char) + 1)))
			return (0);
		while (*line && *line != ' ')
			tab[i][j++] = *(line++);
		tab[i][j] = '\0';
		n = 0;
		j = 0;
		i++;
		line++;
	}
	if (!ft_isdigit(tab[1][0]) || !ft_isdigit(tab[2][0]) || !ft_is_int(tab[1]) \
			|| !ft_is_int(tab[2]))
		return (0);
	return (1);
}

static char **create_tab(char *line, char **tab, int len)
{
	int		i;
	int		j;
	char *tmp;
	int c;

	c = 0;
	i = 0;
	j = 0;
	while (*(line + len) && *(line + len) != ' ')
		len++;
	if (!(tmp = (char*)malloc(len * sizeof(char) + 1)))
			return (NULL);
	len = 0;
	while (tmp[len])
		len++;
	if (!(tab[i] = (char*)malloc(len * sizeof(char) + 1)))
			return (NULL);
	tmp = *ft_strsplit(line, ' ');
	while (tmp[i])
			tab[c][j++] = tmp[i++];
	//free(tmp);
	return (tab);
}

static char **parsetab(t_lemin *lemin, char *line)
{
	char **tab;
	int len;

	len = 0;
	if (!(tab = (char**)malloc(sizeof(char*))))
		return (NULL);
	if (line[0] != 'L' && line[0] != '#' && ft_strchr(line, ' ') && \
		ft_strchr(line, ' ') != ft_strrchr(line, ' ') && !ft_strchr(line, '-'))
		return (create_tab(line, tab, len));
	else
		return (NULL);
}

int readrooms(t_lemin *lemin, char *line)
{
		char **tb;

		lemin->nb_rooms++;
		if (!(lemin->m.cases = (char**)malloc(sizeof(char*))))
			return (0);
		if (!(tb = (char**)malloc(sizeof(char*))))
			return (0);
		if (!(tb = parsetab(lemin, line)))
			return (0);
    lemin->m.cases = tb;
		return (1);
}
