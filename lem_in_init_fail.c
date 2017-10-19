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
	// j->rooms_number = -1;
	j->rooms_done = -1;
	j->way_number = -1;
	// j->g2 = -1;
	// j->g3 = -1;
	// j->g4 = -1;
	// j->g5 = -1;
	j->input = (char *)malloc(sizeof(char));
	j->input[0] = '\0';
	j->room = NULL;
}

void	lem_in_room_init(t_room *room)
{
	ft_bzero(room, sizeof(t_room));
	// room->start = 0;
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

int		lem_in_fail(t_lem *j)
{
	/*зафришить все*/
	write(1, "ERROR\n", 6);
	return (0);
}

t_way	*lem_in_way_init(t_room *room_buf, int vertex)
{
	t_way *memory;

	memory = (t_way *)malloc(sizeof(t_way));
	ft_bzero(memory, sizeof(t_way));
	memory->vertex = vertex;
	memory->room = room_buf;
	memory->next_step = NULL;
	return (memory);
}
