/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_join_strdel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:52:56 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/11 12:52:58 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*lem_in_strjoin(char *t, char *y)
{
	char	*r;
	int		i;
	int		x;

	if (!t || !y)
		return (0);
	if (!(r = (char *)malloc(sizeof(char) * (ft_strlen(t) + ft_strlen(y) + 1))))
		return (0);
	i = 0;
	x = 0;
	while (t[i])
		r[x++] = t[i++];
	i = 0;
	while (y[i])
		r[x++] = y[i++];
	r[x] = '\0';
	ft_strdel(&t);
	ft_strdel(&y);
	return (r);
}
