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

typedef	struct		s_lem
{
	int				error;
	int				ants;
	int				start;
	int				end;
	int				rooms_done;
	int				rooms_number;
	struct	s_room	*rooms;
	int				g1;
	int				g2;
	int				g3;
	int				g4;
	int				g5;
	
}					t_lem;

/*
** error - если была найдена ошибка в карте, равен 1. в ином случае -1.
** ants - количество муравьев. изначально равно -1.
** start - флаг = 1 || 0, если комната старта найдена. = -1, если еще нет
** end - флаг = 1 || 0, если комната финиша найдена. = -1, если еще нет
** rooms_done - равен -1 или 0 если в работе. равен 1, если работа с 
** комнатами завершена, перешли к связям.
** rooms_number - счетчик количества комнат.
** *rooms - ссылка на структуру с комнатами.
** g - итераторы.
*/


typedef	struct		s_room
{
	char			*name;
	int				number;
	int				start;
	int				end;
	char			**links;

}				t_room;
