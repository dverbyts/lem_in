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

void	lem_in_comment(t_lem j, char *l)
{
	if (l[0] == '#' && l[1] != '#')
		return ;
	if (ft_strequ(l, "##end\0") && j->end == -1 && j->ants != -1)
		j->end = 1;
	if (ft_strequ(l, "##start\0") && j->start == -1 && j->ants != -1)
		j->start = 1;
	if (j->start == 1 || j->end == 1)
		return ;
	j->error = 1;
}

void	lem_in_ants(t_lem j, char *l)
{
	j->ants = ft_atoi(l);
	if (j->ants < 1)
		j->error == 1;
}

int		lem_in_is_room(t_lem j, char *l)
{
	if (j->rooms_done == 1)
	{
		j->error = 1;
		return (0);
	}
	j->g3 = 0;
	j->g2 = 1;
	while (l[j->g3] && l[j->g3] != ' ')
		j->g3++;
	while (l[++j->g3])
	{
		if (l[j->g3] == ' ')
			j->g2++;
		else if (ft_isdigit(l[j->g3]) != 1 || j->g2 > 2)
		{
			j->error = 1;
			j->g3 = -1;
			j->g2 = -1;
			return (0);
		}
	}
	j->g3 = -1;
	j->g2 = -1;
	return (1);
}

/*
** j->end == 1 или j->start == 1, тогда это комната старта или конца
** В конце поставить j->end = 0 или j->start = 0 соответственно
*/

t_room	*lem_in_rooms(t_lem j, char *l)
{
	char **buf;
	t_room *r;

	r = (t_room *)malloc(sizeof(t_room));
	lem_in_room_init(r);
	buf = ft_strsplit(l, ' ');
	r->name = ft_strdup(buf[0]);
	r->number = j->++rooms_number;
	if (j->end == 1)
	{
		r->end = 1;
		j->end = 0;
	}
	if (j->start == 1)
	{
		r->start = 1;
		j->start = 0;
	}
	ft_strdel(buf[0]);
	ft_strdel(buf[1]);
	ft_strdel(buf[2]);
	ft_strdel(buf);
	return (r);
}
