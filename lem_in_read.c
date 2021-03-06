/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:12:46 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/09 19:12:48 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_comment(t_lem *j, char *l)
{
	if (l[0] == '#' && l[1] != '#')
		return ;
	if ((j->end != -1 && ft_strequ(l, "##end\0")) ||
		(j->start != -1 && ft_strequ(l, "##start\0")))
	{
		j->error = 1;
		return ;
	}
	if (ft_strequ(l, "##end\0") && j->end == -1 && j->ants != -1)
		j->end = 1;
	if (ft_strequ(l, "##start\0") && j->start == -1 && j->ants != -1)
		j->start = 1;
}

void	lem_in_ants(t_lem *j, char *l)
{
	j->ants = ft_atoi(l);
	while (*l)
	{
		if (ft_isdigit(*l) != 1)
			j->error = 1;
		l++;
	}
	if (j->ants < 1)
		j->error = 1;
}

int		lem_in_is_room(t_lem *j, char *l, int g1)
{
	int g2;

	g2 = 0;
	while (l[g1] && l[g1] != ' ')
		g1++;
	while (l[g1])
	{
		if (l[g1] == ' ')
			g2++;
		else if (ft_isdigit(l[g1]) != 1 || g2 > 2 || l[0] == 'L')
		{
			j->error = 1;
			return (0);
		}
		g1++;
	}
	if (g2 < 2)
		return (0);
	return (1);
}

/*
** j->end == 1 или j->start == 1, тогда это комната старта или конца
** В конце поставить j->end = 0 или j->start = 0 соответственно
*/

void	lem_in_rooms(t_lem *j, char *l)
{
	t_room	*r;
	t_room	*buf;

	if (j->rooms_done == 1 || l[0] == 'L')
	{
		j->error = 1;
		return ;
	}
	r = lem_in_make_room(j, l, -1);
	if (j->room == NULL)
	{
		j->room = r;
		return ;
	}
	buf = j->room;
	while (buf != NULL)
	{
		if ((buf->x == r->x && buf->y == r->y) || ft_strequ(buf->name, r->name))
			j->error = 1;
		buf = buf->next_room;
	}
	buf = j->room;
	while (buf->next_room != NULL)
		buf = buf->next_room;
	buf->next_room = r;
}

t_room	*lem_in_make_room(t_lem *j, char *l, int i)
{
	char	**buf;
	t_room	*r;

	r = (t_room *)malloc(sizeof(t_room));
	lem_in_room_init(r);
	buf = ft_strsplit(l, ' ');
	r->name = ft_strdup(buf[0]);
	r->y = ft_atoi(buf[1]);
	r->x = ft_atoi(buf[2]);
	r->number = ++j->rooms_number;
	if (j->end == 1 && j->start != 1)
	{
		r->end = 1;
		j->end = 0;
	}
	if (j->start == 1 && j->end != 1)
	{
		r->start = 1;
		j->start = 0;
	}
	while (buf[++i])
		ft_strdel(&buf[i]);
	free(buf);
	return (r);
}
