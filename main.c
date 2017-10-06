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
			lem_in_com(j, l);
		else if (ft_isdigit(l[0]) && j->ants == -1)
			lem_in_ants(j, l);



		ft_strdel(&l);
	}

	/*read all*/
}
