/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assign_anthill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:23:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:25:50 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"

void			load_anthill_to_map_points(t_mlx *m, t_lemin *lem)
{
	int		i;

	if (!(m->map_points = (t_point*)ft_memalloc(sizeof(t_point) *
			lem->count_rooms)))
		finish_prog(lem, -1, -1, NULL);
	i = 0;
	while (i < lem->count_rooms)
	{
		m->map_points[i].x0 = lem->rooms[i]->x;
		m->map_points[i].y0 = lem->rooms[i]->y;
		if (lem->rooms[i]->z == NO_DEFINE)
			m->map_points[i].z0 = 0;
		else
			m->map_points[i].z0 = lem->rooms[i]->z;
		if (lem->is_room_color == 1)
		{
			if (lem->rooms[i]->color != NO_DEFINE)
				m->map_points[i].color = lem->rooms[i]->color;
			else
				m->map_points[i].color = 0x101010;
		}
		i++;
	}
	m->quantity_points = lem->count_rooms;
}

void			set_ants_to_start(t_lemin_mlx *lm)
{
	int		i;

	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		lm->ants_move[i].start_room = lm->lem->start_room;
		lm->ants_move[i].end_room = lm->lem->start_room;
		lm->ants_move[i].start = lm->m->map_points[lm->lem->start_room];
		lm->ants_move[i].end = lm->m->map_points[lm->lem->start_room];
		lm->ants_move[i].curr = lm->m->map_points[lm->lem->start_room];
	}
}
