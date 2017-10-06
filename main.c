/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 21:00:19 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/05 21:00:21 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	main(void)
{
	t_lem	*j;

	j = (t_lem *)malloc(sizeof(t_lem));
	lem_in_init(j);
	lem_in_read(j);
	if (j->error == 1)
		return (lem_in_fail(j));

}

void	lem_in_init(t_lem j)
{
	j->error = 0;
	j->ants = -1;
	j->start = -1;
	j->end = -1;
	/*занулить все*/
}

ini		lem_in_fail(t_lem j)
{
	/*зафришить все*/
	write(1, "ERROR\n", 6);

}

void	lem_in_read(t_lem j)
{
	char	*l;

	while (get_next_line(0, &l))
	{
		if (l[0] == "#")
			lem_in_comment(j, l);
		else if (ft_isdigit(l[0]) && j->ants == -1)
			lem_in_ants(j, l);
		else if (ft_isascii[0] && j->ants != -1)
			lem_in_rooms(j, l);
		else
			j->error == 1;
		ft_strdel(&l);
		if (j->error == 1)
			break ;
	}

	/*read all*/
}

void	lem_in_comment(t_lem j, char *l)
{
	int i;
	int len;

	if (l[0] == '#' && l[1] != '#')
		return ;
	len = ft_strlen(l);
	i = 1
	while (l[++i])
	{
		if (i + 6 <= len)
		{
			if (l[i] == 's' && l[i + 1] == 't' && l[i + 2] == 'a' &&
				l[i + 3] == 'r' && l[i + 4] == 't' && j->start == -1)
				j->start = 1;
		}
		else if (i + 3 <= len)
		{
			if (l[i] == 'e' && l[i + 1] == 'n' && l[i + 2] == 'd'
				&& j->end == -1)
				j->end = 1;
		}
	}
	if (j->start == 1 || j->end == 1)
		return ;
	j->error = 1;
}

void	lem_in_rooms(j, lt_lem j, char *l)
{
	/*
	** j->end == 1 или j->start == 1, тогда это комната старта или конца
	** В конце поставить j->end = 0 или j->start = 0 соответственно
	*/
}
