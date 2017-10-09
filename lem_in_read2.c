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

void	lem_in_link(t_lem j, char *l)
{
	char **buf;

	buf = ft_strsplit(l, '-');
	j->g2 = -1;
	while (j->rooms[++j->g2] != NULL)
	{
		if (ft_strequ(buf[0], j->rooms[j->g2]->name))
		{
			
		}
	}
}
