/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_init_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:16:55 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/09 19:16:57 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_init(t_lem *j)
{
	ft_bzero(j, sizeof(t_lem));
	j->ants = -1;
	j->start = -1;
	j->end = -1;
	j->rooms_done = -1;
	j->way_number = -1;
	j->input = ft_strdup("\0");
	j->room = NULL;
}

void	lem_in_room_init(t_room *room)
{
	ft_bzero(room, sizeof(t_room));
	room->vertex = -1;
	room->number = -1;
	room->link = NULL;
	room->ant = -1;
	room->next_room = NULL;
}

void	lem_in_link_init(t_link *link)
{
	ft_bzero(link, sizeof(t_link));
	link->next_link = NULL;
	link->link_room = NULL;
}

t_way	*lem_in_way_init(t_room *room_buf, int vertex)
{
	t_way	*memory;

	memory = (t_way *)malloc(sizeof(t_way));
	ft_bzero(memory, sizeof(t_way));
	memory->vertex = vertex;
	memory->room = room_buf;
	memory->next_step = NULL;
	return (memory);
}

char	*lem_in_strjoin(char *t, char *y)
{
	char	*r;
	int		i;
	int		x;

	if (!t || !y)
		return (0);
	if (!(r = (char *)malloc(sizeof(char) * (ft_strlen(t) + ft_strlen(y) + 1))))
		return (0);
	i = 0;
	x = 0;
	while (t[i])
		r[x++] = t[i++];
	i = 0;
	while (y[i])
		r[x++] = y[i++];
	r[x] = '\0';
	ft_strdel(&t);
	ft_strdel(&y);
	return (r);
}
