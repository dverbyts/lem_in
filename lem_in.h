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
	int				way_number;
	struct s_way	**way;
	struct s_room	*room;
}					t_lem;

/*
** Основнас структура программы
**
** input - тут сохраняем что получила программа на вход.
** error - если была найдена ошибка в карте, равен 1. в ином случае -1.
** ants - количество муравьев. изначально равно -1.
** start - флаг = 1 || 0, если комната старта найдена. = -1, если еще нет
** end - флаг = 1 || 0, если комната финиша найдена. = -1, если еще нет
** rooms_done - равен -1 или 0 если в работе. равен 1, если работа с
** комнатами завершена, перешли к связям.
** rooms_number - счетчик количества комнат.
** way_number - изначально равен -1. когда определяемся который из
** имеющихся путей использовать, его номер записываем сюда.
** way - тут я храню все пути, которые нашла программа.
** room - ссылка на структуру с комнатами.
*/

typedef	struct		s_room
{
	char			*name;
	int				number;
	int				vertex;
	int				start;
	int				end;
	int				ant;
	int				x;
	int				y;
	struct s_link	*link;
	struct s_room	*next_room;
}					t_room;

/*
** Структура под комнаты
**
** name - имя комнаты, заданное при вводе.
** number - уникальный номер комнаты.
** vertex - равно -1. при поиске пути записывая очередность в которой
** зашел в эту комнату.
** start - если == 1, это стартовая комната
** end - если == 1, это финишная комната
** ant - количество муравьев в комнате / номер муравья в комнате
** х и у - координаты комнаты. сраню, не использую.
** link - ссылка на связи с другими комнатами.
** next_room - ссылка на следующую комнату.
*/

typedef struct		s_link
{
	int				home_number;
	int				link_number;
	struct s_room	*link_room;
	struct s_link	*next_link;
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

typedef struct		s_way
{
	int				vertex;
	struct s_room	*room;
	struct s_way	*next_step;
}					t_way;

/*
** Поиск и карта пути от старта к выходу
**
** vertex - длина/количество переходов между комнатами. для выбора самого
** короткого пути.
** link - ссылка на нужный переход между комнатами.
** next_step - следующий шаг на пути к выходу.
*/

int					main(void);
void				lem_in_read(t_lem *j);
void				lem_in_init(t_lem *j);
void				lem_in_room_init(t_room *room);
void				lem_in_link_init(t_link *link);
t_way				*lem_in_way_init(t_room *room_buf, int vertex);
void				lem_in_save_input(t_lem *j, char *l, int i);
int					lem_in_is_link(t_lem *j, char *l, int re, int i);
int					lem_in_is_link2(t_lem *j, char **buf, int re);
void				lem_in_links(t_lem *j, int i, char **splt);
void				lem_in_links2(t_lem *j, t_room *room_buf, char **splt);
t_link				*lem_in_make_link(t_lem *j, t_room *room_buf, char **splt);
void				lem_in_comment(t_lem *j, char *l);
void				lem_in_ants(t_lem *j, char *l);
int					lem_in_is_room(t_lem *j, char *l, int g1);
void				lem_in_rooms(t_lem *j, char *l);
t_room				*lem_in_make_room(t_lem *j, char *l, int i);
char				*lem_in_strjoin(char *t, char *y);
void				lem_in_find_way(t_lem *j);
void				lem_in_recursion(t_lem *j, t_room *room, int vertex,
					t_way *way);
int					lem_in_save_way(t_lem *j, t_room *room, t_way *way);
t_way				**lem_in_we_have_way(t_lem *j, t_way *way, int e);
void				lem_in_del_steps(t_way *w1, int vertex);
void				lem_in_go_ants(t_lem *j, int l);
t_way				*lem_in_revert_way(t_lem *j, int l);
void				lem_in_go_go_ants(t_lem *j, int l);
int					lem_in_wich_way(t_lem *j, int e, int i, int l);

#endif
