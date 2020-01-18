/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assign_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:16:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:02:29 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			set_num_rooms_to_ant_moves(t_lemin *l)
{
	int			i;
	t_dlist		*curr;
	t_ant_move	*am;

	i = -1;
	while (++i < l->number_of_ants)
	{
		curr = l->ants_moving[i];
		while (curr != NULL)
		{
			am = curr->content;
			am->to = room_number(l, am->to_name);
			l->rooms[am->to]->flow = 1;
			l->count_all_edges_moving++;
			curr = curr->next;
		}
	}
	if (errno)
		finish_prog(l, -1, -1, NULL);
}

static void		set_start_flow(t_lemin *l, t_ant_move *am)
{
	int j;

	j = -1;
	while (++j < l->count_edges)
		if ((l->edges[j].from == l->start_room && l->edges[j].to == am->to) ||
			(l->edges[j].from == am->to && l->edges[j].to == l->start_room))
			l->edges[j].flow = 1;
}

static void		set_edges_flow(t_lemin *l, t_dlist *curr, t_ant_move *am)
{
	int			j;
	t_ant_move	*am_next;

	while (curr != NULL && curr->next != NULL)
	{
		am = curr->content;
		am_next = curr->next->content;
		j = -1;
		while (++j < l->count_edges)
		{
			if ((l->edges[j].from == am->to && l->edges[j].to == am_next->to) ||
				(l->edges[j].to == am->to && l->edges[j].from == am_next->to))
				l->edges[j].flow = 1;
			l->rooms[am->to]->flow = 1;
			l->rooms[am_next->to]->flow = 1;
		}
		curr = curr->next;
	}
}

void			set_flow_anthill(t_lemin *l)
{
	int			i;
	t_dlist		*curr;
	t_ant_move	*am;

	l->rooms[l->start_room]->flow = 1;
	i = -1;
	while (++i < l->number_of_ants)
	{
		curr = l->ants_moving[i];
		am = curr->content;
		set_start_flow(l, am);
		set_edges_flow(l, curr, am);
	}
}
