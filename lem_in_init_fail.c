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

void	lem_in_init(t_lem j)
{
	j->error = 0;
	j->ants = -1;
	j->start = -1;
	j->end = -1;
	j->rooms_number = -1;
	j->rooms_done = -1;
	j->g1 = -1;
	j->g2 = -1;
	j->g3 = -1;
	j->g4 = -1;
	j->g5 = -1;
	/*занулить все*/
}

void	lem_in_room_init(t_room *room)
{
	room->start = 0;
	room->end = 0;
	room->number = -1;
}

ini		lem_in_fail(t_lem j)
{
	/*зафришить все*/
	write(1, "ERROR\n", 6);

}
