/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:17:03 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/13 14:17:05 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h> // DELETE ME!!!
#include "lem_in.h"

void	lem_in_find_way(t_lem *j)
{
	t_room	*room_buf;

	room_buf = j->room;
	while (room_buf->start != 1)
		room_buf = room_buf->next_room;
	j->way = (t_way **)malloc(sizeof(t_way *));
	ft_bzero(j->way, sizeof(t_way**));
	if (lem_in_recursion(j, room_buf, 0, 0) < 1)
		j->error = 1;
}



int		lem_in_recursion(t_lem *j, t_room *room, int vertex, int f)
{
	t_link	*buf;

	if (room->vertex < vertex && room->vertex != -1)
		return (0);
	if (room->end == 1)
		return (1);
	buf = room->link;
	room->vertex = vertex;
	while (buf != NULL)
	{
		f = lem_in_recursion(j, buf->link_room, vertex + 1, 0);
		if (f > 0 && f < 4)
			j->way = lem_in_check_way(j, buf->link_room, vertex + 1);
		buf = buf->next_link;
	}
	return (j->way[0] == NULL ? 0 : 3);
}

t_way	**lem_in_check_way(t_lem *j, t_room *room, int vertex)
{
	t_way	*way_buf;
	int		z;
	
	if (j->way[j->way_number] == NULL)
		j->way[j->way_number] = lem_in_way_init(room, vertex);
	else
	{
		way_buf = j->way[j->way_number];
		while (way_buf->next_step != NULL)
			way_buf = way_buf->next_step;
		way_buf->next_step = lem_in_way_init(room, vertex);
	}
	way_buf = j->way[j->way_number];
	z = j->way[j->way_number]->vertex;
	while (way_buf != NULL)
	{
		if (z == 1 && way_buf->next_step == NULL && vertex == 1)
			return (j->way = lem_in_more_way(j));
		z--;
		way_buf = way_buf->next_step;
	}
	way_buf = j->way[j->way_number];  // DELETE ME!!!
	while (way_buf != NULL)  // DELETE ME!!!
	{
		printf("%s %d\n", way_buf->room->name, way_buf->room->number);  // DELETE ME!!!
		way_buf = way_buf->next_step;  // DELETE ME!!!
	}  // DELETE ME!!!
	printf("\n");  // DELETE ME!!!
	return (j->way);
}

t_way	**lem_in_more_way(t_lem *j)
{
	t_way	**new;
	int		z;

	j->way_number += 1;
	new = (t_way **)malloc(sizeof(t_way *) * (j->way_number + 1));
	ft_bzero(j->way, sizeof(t_way**) * (j->way_number + 1));
	z = -1;
	while (++z <= j->way_number)
		new[z] = NULL;
	z = -1;
	while (++z <= j->way_number)
		new[z] = j->way[z];
	free(j->way);
	j->way = new;
	return (j->way);
}
