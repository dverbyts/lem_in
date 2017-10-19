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

int	main(void)
{
	t_lem	*j;

	j = (t_lem *)malloc(sizeof(t_lem));
	lem_in_init(j);
	lem_in_read(j);
	if (j->error == 1)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	lem_in_find_way(j);
	if (j->error == 1)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	ft_printf("%s", j->input);
	lem_in_go_ants(j, 0);
//	LEAK;
	return (1);
}

void	lem_in_read(t_lem *j)
{
	char	*l;

	while (get_next_line(0, &l) == 1)
	{
		lem_in_save_input(j, l, 0);
		if (l[0] == '#' && (j->end != 1 || j->end != 1))
			lem_in_comment(j, l);
		else if (ft_isdigit(l[0]) && j->ants == -1)
			lem_in_ants(j, l);
		else if (ft_isascii(l[0]) && j->ants != -1 && lem_in_is_room(j, l, 0) &&
			l[0] != '#')
			lem_in_rooms(j, l);
		else if (l[0] != '\0' && ft_isascii(l[0]) && j->ants != -1 &&
				lem_in_is_link(j, l, -1, -1) && (j->end != 1 || j->end != 1))
			lem_in_links(j, -1, ft_strsplit(l, '-'));
		else
			j->error = 1;
		ft_strdel(&l);
		if (j->error == 1)
			break ;
	}
	if (j->input[0] == '\0')
		j->error = 1;
}

void	lem_in_save_input(t_lem *j, char *l, int i)
{
	while (l[i])
	{
		if (l[i] == '\n' && l[i + 1] == '\0')
		{
			j->input = lem_in_strjoin(j->input, ft_strdup(l));
			return ;
		}
		i++;
	}
	j->input = lem_in_strjoin(j->input, ft_strdup(l));
	j->input = lem_in_strjoin(j->input, ft_strdup("\n\0"));
}
