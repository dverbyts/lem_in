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

#include "lem_in.h"

void	lem_in_find_way(t_lem *j)
{
	t_room *room_start;
	t_link *link_buf;
	
	
	room_start = j->room;
	while (room_start->start != 1)
		room_start = room_start->next_room;
	link_buf = j->room->link;
}
