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
	l = lem_in_wich_way(j, -1, -1, -1);
	ft_printf("\n");
	j->way[l]->room->ant = j->ants;
	j->way[l] = lem_in_revert_way(j, l);
	lem_in_go_go_ants(j, l);
}

t_way	*lem_in_revert_way(t_lem *j, int l)
{
	t_way *prev;
	t_way *current;
	t_way *next;

	prev = NULL;
	current = j->way[l];
	j->way[l] = NULL;
	while (current != NULL)
	{
		next = current->next_step;
		current->next_step = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

void	lem_in_go_go_ants(t_lem *j, int l)
{
	t_way *buf;

	while ((j->way[l]->room->ant + 1) < j->ants)
	{
		buf = j->way[l];
		while (buf != NULL)
		{
			if ((buf->room->ant + 1) == j->ants || buf->next_step == NULL)
				break ;
			if (buf->next_step->room->ant > -1 && buf->room->ant < j->ants)
			{
				buf->room->ant += 1;
				write(1, "L", 1);
				ft_putnbr(1 + buf->room->ant);
				write(1, "-", 1);
				ft_putstr(buf->room->name);
				write(1, " ", 1);
			}
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
