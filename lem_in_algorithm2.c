/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algorithm2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 20:06:23 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/18 20:06:24 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_go_ants(t_lem *j, int l)
{
	t_way *end;
	t_way *buf;

	buf = j->way[l];
	while (buf->next_step != NULL)
		buf = buf->next_step;
	end = buf;
	l = lem_in_wich_way(j, -1, -1, -1);
	lem_in_go_go_ants(j, l, end);
}

void	lem_in_go_go_ants(t_lem *j, int l, t_way *end)
{
	t_way *buf;

	while (end->room->ant <= j->ants)
	{
		buf = j->way[l];
		while (buf->next_step != NULL)
		{
			while (buf->next_step->room->ant + 1 == j->ants)
			{
				buf = buf->next_step;
				if (buf->next_step == NULL)
					return ;
			}
			buf->next_step->room->ant += 1;
			ft_printf("L%d-%s", buf->next_step->room->ant + 1,
				buf->next_step->room->name);
			if (buf->next_step->room->ant == 0)
				break ;
			buf = buf->next_step;
		}
		write(1, "\n", 1);
	}
}

int		lem_in_wich_way(t_lem *j, int e, int i, int l)
{
	t_way	*b;
	int		w;

	w = -1;
	while (++e <= j->way_number)
	{
		b = j->way[e];
		i = -1;
		while (b->next_step != NULL)
		{
			++i;
			b = b->next_step;
		}
		if (w == -1 || w > i)
		{
			w = i;
			l = e;
		}
	}
	return (l);
}
