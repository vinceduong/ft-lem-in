#ifndef ERROR_H
# define ERROR_H
# include "lem_in.h"

typedef	struct		s_error
{
	char	*reason;
	int		type_error;
	char	*str_print;

}					t_error;

t_error tab_errors[] =
{
	{(char *)"room_add", -1, (char *)"Error: room was already added."},
	{(char *)"empty_line", -1, (char *)"Error: an empty line has been found."},
	{(char *)"wrong_ants", -1, (char *)"Error: wrong number of ants."},
	{(char *)"noadd_ants", -1, (char *)"Error: ant couldn't be created."},
	{(char *)"many_starts", -1, (char *)"Error: too many start rooms."},
	{(char *)"many_ends", -1, (char *)"Error: too many end rooms."},
	{(char *)"link_format", -1, (char *)"Error: link can't be created."},
	{(char *)"line_format", -1, (char *)"Error: line can't be recognized."},
	{(char *)"link_room1", -1, (char *)"Error: room1 in link doesn't exist."},
	{(char *)"link_room2", -1, (char *)"Error: room2 in link doesn't exist."},
	{(char *)"link_loop", -1, (char *)"Error: a room cannot be link to itself."}
	,
	{(char *)"room_unfound", -1, (char *)"Error: room can't be found."},
	{(char *)"duplicate_link", -1, (char *)"Error: link was created sooner."},
	{(char *)"coord_error", 0, (char *)"Error: wrong coordinates."},
	{(char *)"l_room", 0, (char *)"Error: room name starts with an 'L'."},
	{(char *)"room_load", -2, (char *)"Error: room couldn't be loaded."},
	{(char *)"no_start", -2, (char *)"Error: room start does not exist."},
	{(char *)"no_end", -2, (char *)"Error: the end has no end."},
	{(char *)"start_unlinked", -2, (char *)"Error: room start has no link."},
	{(char *)"end_unlinked", -2, (char *)"Error: room end has no end."},
	{(char *)"se_error", -2, (char *)"Error: expecting start and end rooms."},

};

#endif
