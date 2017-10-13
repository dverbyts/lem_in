/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_read2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:14:46 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/09 19:14:48 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_is_link(t_lem *j, char *l, int re)
{
	char **buf;
	t_room *room_buf;

	buf = ft_strsplit(l, '-');
	if (buf == NULL)
		return (0);
	if (ft_strequ(buf[0], l))
		re = 0;
	room_buf = j->room;
	while (room_buf != NULL && re == -1)
	{
		if (ft_strequ(buf[0], room_buf->name))
		{
			if (j->rooms_done != 1)
				j->rooms_done = 1;
			re += 1;
		}
		room_buf = room_buf->next_room;
	}
	re = lem_in_is_link2(j, buf, re);
	while (*buf++)
		ft_strdel(buf);
	free(buf);
	return (re);
}

int		lem_in_is_link2(t_lem *j, char **buf, int re)
{
	t_room *room_buf;

	if (re == -1)
		return (0);
	if (j->rooms_done == 1 && (j->start == -1 || j->end == -1))
		j->error = 1;
	room_buf = j->room;
	while (room_buf != NULL && re == 0)
	{
		if (ft_strequ(buf[1], room_buf->name))
			re += 1;
		room_buf = room_buf->next_room;
	}
	if (re == 0)
		j->error = 1;
	return (re);
}

void	lem_in_links(t_lem *j, char *l, int i, char **splt)
{
	t_room *room_buf;
	t_link *buf;

	room_buf = j->room;
	while (room_buf != NULL)
	{
		if (ft_strequ(room_buf->name, splt[0]))
		{
			if ((buf = room_buf->link) == NULL)
				room_buf->link = lem_in_make_link(j, room_buf, splt);
			else
			{
				while (buf->next_link != NULL)
					buf = buf->next_link;
				buf->next_link = lem_in_make_link(j, room_buf, splt);;
			}
			lem_in_links2(j, room_buf, splt);
			break ;
		}
		room_buf = room_buf->next_room;
	}
	while (splt[++i])
		ft_strdel(&splt[i]);
	free(splt);
}

void	lem_in_links2(t_lem *j, t_room *room_buf, char **splt)
{
	t_link *buf;
	char *temp;

	temp = splt[0];
	splt[0] = splt[1];
	splt[1] = temp;
	room_buf = j->room;
	while (room_buf != NULL)
	{
		if (ft_strequ(room_buf->name, splt[0]))
		{
				if ((buf = room_buf->link) == NULL)
					room_buf->link = lem_in_make_link(j, room_buf, splt);
				else
				{
					while (buf->next_link != NULL)
						buf = buf->next_link;
					buf->next_link = lem_in_make_link(j, room_buf, splt);
				}
			break ;
		}
		room_buf = room_buf->next_room;
	}
}

t_link	*lem_in_make_link(t_lem *j, t_room *room_buf, char **splt)
{
	t_link *r;
	t_room *room;

	r = (t_link *)malloc(sizeof(t_link));
	lem_in_link_init(r);
	r->home_number = room_buf->number;
	room = j->room;
	while (room != NULL)
	{
		if (ft_strequ(room->name, splt[1]))
		{
			r->link_number = room->number;
			r->link_room = room;
			return (r);
		}
		room = room->next_room;
	}
	j->error = 1;
	return (NULL);
}
