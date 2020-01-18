/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:29:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:37:23 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <time.h>

# define INF 1e9
# define LEMIN_DEBUG 0

typedef struct		s_room
{
	char			*name;
	int				number;
	int				x;
	int				y;
	int				z;
	int				color;
	int				start_end_flag;
	int				flow;
}					t_room;

typedef struct		s_room_ways
{
	char			*start_room;
	char			*end_room;
}					t_room_ways;

typedef struct		s_edge
{
	int				from;
	int				to;
	int				capacity;
	int				cost;
	int				flow;
}					t_edge;

typedef struct		s_gedge
{
	int				to;
	int				cap;
	int				flow;
	int				flow1;
}					t_gedge;

typedef struct		s_start_end
{
	int				start;
	int				end;
}					t_start_end;

typedef struct		s_ant_move
{
	int				step;
	char			*to_name;
	int				to;
}					t_ant_move;

typedef struct		s_lemin
{
	int				is_visu;
	int				is_room_color;
	t_dlist			*list_rooms;
	t_dlist			*room_ways;
	int				count_rooms;
	int				start_room;
	int				end_room;
	int				number_of_ants;
	int				count_edges;
	t_edge			*edges;
	t_room			**rooms;


	int				**ants_on_ways;
	int				max_ways;

	int				**ways;
	int				*way_length;
	int				count_ways;
	int				count_steps;

	int				**prev_ways;
	int				*prev_way_length;
	int				prev_count_ways;
	int				prev_count_steps;

	int				*ants_left_on_ways;

	int				size_matrix;

	t_dlist			**g;
	int				*push;
	int				*mark;
	int				*pred;
	int				max_flow;
	int				s;
	int				t;

	t_dlist			**ants_moving;
	int				count_all_edges_moving;
	int				current_step;
	int				max_step;
}					t_lemin;

/*
** initialize
*/

void				tlemin_initialize(t_lemin *lemin);

/*
** destroy
*/

void				lemin_destroy(t_lemin *lemin);
void				finish_prog(t_lemin *l, int res, int fd, char **line);
void				destroy_room(void *room, size_t size);
void				destroy_ant_move(void *ant_move, size_t size);
void				destroy_way(void *room_ways, size_t size);

/*
** load data from file
*/

void				load_and_prepare_lemin(t_lemin *lemin, int argc, char **argv);
void				open_file_load_data(t_lemin *lemin, int argc, char **argv);
void				load_data(t_lemin *lemin, int fd);
t_room				set_room_property(char **strings, int next_flag);
int					find_duplicates_rooms(t_dlist *list_rooms,
											t_room room_temp);
void				load_room(t_lemin *lemin, char **line, int *next_flag,
								int fd);
void				load_number_of_ants(t_lemin *lemin, int fd);
void				set_numbers_rooms(t_lemin *lemin);
void				check_data(t_lemin *l);
/*
** prepare data
*/

void				prepare_data(t_lemin *lemin);
void				lemin_fill_graph(t_lemin *lem);
void				lemin_init_ways(t_lemin *l);
int					room_number(t_lemin *lemin, char *room_name);

/*
** solve
*/

void				solve(t_lemin *l);
int					bfs(t_lemin *lem);
int					bfs_ways(t_lemin *lem);
void				calculate_ways(t_lemin *l);

/*
** going ants
*/

void				going_ants(t_lemin *l);
int					count_bandwidth(int flow_len, int step);

/*
** print
*/

void				print_anthill(t_lemin *l);

#endif
