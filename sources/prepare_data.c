/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:55:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:32:30 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "ft_timer.h"

static void		edges_assign(t_lemin *lemin)
{
	t_dlist		*curr;
	int			i;

	if (!(lemin->edges = (t_edge*)ft_memalloc(sizeof(t_edge) *
							lemin->count_edges)))
		finish_prog(lemin, -1, -1, NULL);
	i = 0;
	curr = lemin->room_ways;
	while (i < lemin->count_edges)
	{
		lemin->edges[i].from = room_number(lemin,
								((t_room_ways*)(curr->content))->start_room);
		lemin->edges[i].to = room_number(lemin,
								((t_room_ways*)(curr->content))->end_room);
		lemin->edges[i].capacity = 1;
		lemin->edges[i].cost = 1;
		i++;
		curr = curr->next;
		if (errno != 0)
			finish_prog(lemin, -1, -1, NULL);
	}
}

static void		lemin_init_arrays(t_lemin *lemin)
{
	if (!(lemin->push = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	if (!(lemin->mark = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	if (!(lemin->pred = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	lemin->max_flow = 0;
}

static void		lemin_fill_rooms(t_lemin *lem)
{
	int		i;
	t_dlist *curr;

	if (!(lem->rooms = (t_room**)ft_memalloc(sizeof(t_room*) *
						lem->count_rooms)))
		finish_prog(lem, -1, -1, NULL);
	curr = lem->list_rooms;
	i = 0;
	while (i < lem->count_rooms)
	{
		(lem->rooms)[i] = (t_room*)(curr->content);
		i++;
		curr = curr->next;
	}
}

int				rooms_compare(t_room *room1, t_room *room2)
{
	return (ft_strcmp(room1->name, room2->name));
}

void			check_doubles_room_names(t_lemin *l)
{
	int		i;

	i = -1;
	while (++i < l->count_rooms - 1)
		if (ft_strequ(l->rooms[i]->name, l->rooms[i + 1]->name))
			finish_prog(l, -1, -1, NULL);
}

void			prepare_data(t_lemin *lemin)
{
	lemin_fill_rooms(lemin);
	ft_sort_quick((void**)lemin->rooms, 0, lemin->count_rooms - 1, rooms_compare);
	check_doubles_room_names(lemin);
	set_numbers_rooms(lemin);
	errno = 0;
	edges_assign(lemin);
	lemin_init_arrays(lemin);
	lemin_fill_graph(lemin);
	lemin_init_ways(lemin);
}
