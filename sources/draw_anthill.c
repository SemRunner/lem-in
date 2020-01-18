/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:34:28 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"

static void		draw_start_end_room(t_lemin_mlx *lm, int not_black,
									int color_frontier, int i)
{
	t_point p;

	p = lm->m->map_points[i];
	p.color = color_frontier;
	putbox(lm->m, lm->m->map_points[i], lm->size_ant_im + 2, not_black);
	putbox(lm->m, lm->m->map_points[i], lm->size_ant_im + 4, not_black);
	putbox(lm->m, p, lm->size_ant_im + 6, not_black);
	putbox(lm->m, p, lm->size_ant_im + 8, not_black);
	putbox_full(lm->m, lm->m->map_points[i], lm->size_ant_im, 0);
}

void			draw_intermed_room_aux(t_lemin_mlx *lm, int not_black, int i)
{
	if (lm->show_interm_rooms == 0)
		putbox(lm->m, lm->m->map_points[i], 1, not_black);
	else
	{
		putbox(lm->m, lm->m->map_points[i],
				lm->size_ant_im + 2, not_black);
		putbox(lm->m, lm->m->map_points[i],
				lm->size_ant_im + 4, not_black);
		putbox_full(lm->m, lm->m->map_points[i], lm->size_ant_im, 0);
	}
}

static void		draw_intermed_room(t_lemin_mlx *lm, int not_black, int i)
{
	if (lm->show_not_use_edges == 0)
	{
		if (lm->lem->rooms[i]->flow == 1)
			draw_intermed_room_aux(lm, not_black, i);
		else
		{
			if (lm->show_interm_rooms == 0)
				draw_intermed_room_aux(lm, not_black, i);
		}
	}
	else
		draw_intermed_room_aux(lm, not_black, i);
	if (lm->lem->rooms[i]->flow == 1 && (lm->show_ways == 0 ||
		lm->show_ways == 2))
		putbox(lm->m, lm->m->map_points[i], 4, not_black);
}

static void		draw_rooms(t_lemin_mlx *lm, int not_black)
{
	int		i;

	i = -1;
	while (++i < lm->lem->count_rooms)
	{
		if (i != lm->lem->start_room && i != lm->lem->end_room)
			draw_intermed_room(lm, not_black, i);
	}
	draw_start_end_room(lm, not_black, 0xFF0000, lm->lem->start_room);
	draw_start_end_room(lm, not_black, 0x00FF00, lm->lem->end_room);
}

void			draw_anthill(t_lemin_mlx *lm, int not_black)
{
	draw_ways(lm, not_black);
	draw_rooms(lm, not_black);
}
