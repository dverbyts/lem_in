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
# include "libft/libft.h"

typedef	struct		s_lem
{
	char			*input;
	int				error;
	int				ants;
	int				start;
	int				end;
	int				rooms_done;
	int				rooms_number;
	struct	s_room	*room;
	// int				g1;
	// int				g2;
	// int				g3;
	// int				g4;
	// int				g5;
	
}					t_lem;

/*
** Основнас структура программы
**
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
	int				ant;
	struct	s_link	*link;
	struct	s_room	*next_room;
}					t_room;

/*
** Структура под комнаты
**
** name - имя комнаты, заданное при вводе.
** number - уникальный номер комнаты.
** start - если == 1, это стартовая комната
** end - если == 1, это финишная комната
** ant - количество муравьев в комнате / номер муравья в комнате
** link - ссылка на связи с другими комнатами
*/

typedef struct 		s_link
{
	int				home_number;
	int				link_number;
	struct	s_room	*link_room;
	struct	s_link	*next_link;
}					t_link;

/*
** Структура под связи между комнатами
**
** home_number - уникальный номер родительской комнаты
** link_number - уникальный номер комнаты, с которой связана родительская
** комната.
** room - ссылка на родительскую комнату
** link - ссылка на связи с другими комнатами
*/

int		main(void);
void	lem_in_read(t_lem *j);
void	lem_in_init(t_lem *j);
void	lem_in_room_init(t_room *room);
void	lem_in_link_init(t_link *link);
int		lem_in_fail(t_lem *j);
void	lem_in_save_input(t_lem *j, char *l, int i);
int		lem_in_is_link(t_lem *j, char *l, int re);
void	lem_in_links(t_lem *j, char *l, int i);
t_link	*lem_in_make_link(t_lem *j, t_room *room_buf, char **splt);
void	lem_in_insert_link(t_link *r, t_room *room_buf);
void	lem_in_comment(t_lem *j, char *l);
void	lem_in_ants(t_lem *j, char *l);
int		lem_in_is_room(t_lem *j, char *l, int g1, int g2);
void	lem_in_rooms(t_lem *j, char *l);
t_room	*lem_in_make_room(t_lem *j, char *l);
char	*lem_in_strjoin(char *t, char *y);


#endif
