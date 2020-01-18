/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anthill1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 17:39:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"

void		draw_ways_ant_moves(t_lemin_mlx *lm, int not_black)
{
	int			i;
	t_dlist		*curr;
	int			start_point;
	t_ant_move	*am;

	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		start_point = lm->lem->start_room;
		curr = lm->lem->ants_moving[i];
		while (curr != NULL)
		{
			am = curr->content;
			putline_thick(lm->m, lm->m->map_points[start_point],
						lm->m->map_points[am->to], not_black);
			start_point = am->to;
			curr = curr->next;
		}
	}
}

void		draw_ways(t_lemin_mlx *lm, int not_black)
{
	int i;
	int n1;
	int n2;

	i = -1;
	while (++i < lm->lem->count_edges)
	{
		n1 = lm->lem->edges[i].from;
		n2 = lm->lem->edges[i].to;
		if (lm->lem->edges[i].flow == 1)
			putline_thick(lm->m, lm->m->map_points[n1],
						lm->m->map_points[n2], not_black);
		else
		{
			if (lm->show_not_use_edges == 1)
				putline(lm->m, lm->m->map_points[n1],
						lm->m->map_points[n2], not_black);
		}
	}
	if (lm->show_ways == 1 || lm->show_ways == 2)
		draw_ways_ant_moves(lm, not_black);
}

void		remove_anthill_from_image(t_lemin_mlx *lm)
{
	clear_image(lm->m);
}

void		put_anthill_to_image(t_lemin_mlx *lm)
{
	make_map_points(lm->m);
	draw_anthill(lm, 1);
	put_all_anthill(lm);
}
