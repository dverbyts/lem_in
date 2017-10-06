/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 21:16:42 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/05 21:16:45 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
#include "libft/libft.h"

typedef	struct	s_lem
{
	int			error;
	int			ants;
	int			start;
	int			end;
	
}				t_lem;

typedef	struct	s_room
{
	char		*name;
	
}				t_room;
