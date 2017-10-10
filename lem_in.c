/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
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
	ft_putstr(j->input[0]);
	if (j->error == 1)
		return (lem_in_fail(j));

}

void	lem_in_read(t_lem j)
{
	char	*l;

	j->g1 = 0;
	while (get_next_line(0, &l))
	{
		lem_in_save_input(j, l, 0);
		if (l[0] == "#")
			lem_in_comment(j, l);
		else if (ft_isdigit(l[0]) && j->ants == -1)
			lem_in_ants(j, l);
		else if (ft_isascii[0] && j->ants != -1 && lem_in_is_room(j, l) &&
			j->rooms_done != 1)
			lem_in_rooms(j, l);
		else if (ft_isascii[0] && j->ants != -1 && lem_in_is_link(j, l))
			lem_in_links(j, l, -1);
		else
			j->error == 1;
		ft_strdel(&l);
		if (j->error == 1)
			break ;
	}
	/*read all*/
}
