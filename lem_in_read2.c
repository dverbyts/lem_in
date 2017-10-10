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

void	lem_in_save_input(t_lem j, char *l, int i)
{
	while (l[i]);
	{
		if (l[i] == '\n' && l[i + 1] == '\0')
		{
			j->input = ft_strjoin(j->input, ft_strdup(l));
			return ;
		}
		i++;
	}
	j->input = ft_strjoin(j->input, ft_strdup(l));
	j->input = ft_strjoin(j->input, "\n\0");
}

int		lem_in_is_link(t_lem j, char *l)
{
	char **buf;
	int	re;

	j->g2 = -1;
	re = -1;
	buf = ft_strsplit(l, '-');
	if (ft_strequ(buf[0], l))
		re = 0;
	while (j->rooms[++j->g2] != NULL && re == -1)
	{
		if (ft_strequ(buf[0], j->rooms[j->g2]->name))
		{
			if (j->rooms_done != 1)
				j->rooms_done = 1;
			re = 1;
		}
	}
	while (*buf++)
		ft_strdel(*buf);
	ft_strdel(buf);
	if (re == -1)
		re = 0;
	return (re);
}

void	lem_in_links(t_lem j, char *l, int i)
{
	t_room *room_buf;
	t_link *r;
	t_link *buf;
	char **splt;

	splt = ft_strsplit(l, '-');
	room_buf = j->room;
	while (room_buf != NULL)
	{
		if (ft_strequ(room_buf->name, splt[0]))
		{
			r = lem_in_make_link(j, room_buf, splt);
			if (r == NULL)
				break ;
			if (room_buf->link == NULL)
				room_buf->link = r;
			else
				lem_in_insert_link();
			break ;
		}
		room_buf = room_buf->next_room;
	}
	while (splt[++i])
		ft_strdel(splt[i]);
	ft_strdel(splt);
}

t_link	lem_in_make_link(t_lem j, t_room room_buf, char **splt)
{
	t_link *r;
	t_link *link_buf;
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

void	lem_in_insert_link(t_link *r, t_room room_buf)
{
	t_link *buf;

	buf = room_buf->link;
	while (buf->next_link != NULL)
		buf = buf->next_link;
	buf->next_link = r;
}
