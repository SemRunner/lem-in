/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:22:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:34:57 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		lemin_init_aux(t_lemin *lemin)
{
	lemin->g = NULL;
	lemin->push = NULL;
	lemin->mark = NULL;
	lemin->pred = NULL;
	lemin->max_flow = 0;
	lemin->s = -1;
	lemin->t = -1;
	lemin->ants_moving = NULL;
	lemin->current_step = 0;
	lemin->max_step = 0;
	lemin->count_all_edges_moving = 0;
	lemin->is_visu = 0;
	lemin->is_room_color = 0;
}

void			tlemin_initialize(t_lemin *lemin)
{
	lemin->list_rooms = NULL;
	lemin->room_ways = NULL;
	lemin->count_rooms = 0;
	lemin->start_room = -1;
	lemin->end_room = -1;
	lemin->number_of_ants = 0;
	lemin->count_edges = 0;
	lemin->edges = NULL;
	lemin->rooms = NULL;
	lemin->ants_on_ways = NULL;
	lemin->max_ways = 0;
	lemin->ways = NULL;
	lemin->way_length = NULL;
	lemin->count_ways = 0;
	lemin->count_steps = 0;
	lemin->prev_ways = NULL;
	lemin->prev_way_length = NULL;
	lemin->prev_count_ways = 0;
	lemin->prev_count_steps = 0;
	lemin->ants_left_on_ways = NULL;
	lemin->size_matrix = 0;
	lemin_init_aux(lemin);
}
