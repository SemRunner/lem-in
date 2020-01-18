/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:23:09 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:23:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"

static void		set_ant_move(t_lemin_mlx *lm, t_ant_draw_move *ant_move)
{
	double step_x;
	double step_y;

	if (ant_move->start_room == ant_move->end_room)
	{
		ant_move->curr = lm->m->map_points[ant_move->start_room];
		return ;
	}
	ant_move->start = lm->m->map_points[ant_move->start_room];
	ant_move->end = lm->m->map_points[ant_move->end_room];
	step_x = (double)(ant_move->end.x - ant_move->start.x) / ((float)lm->speed);
	step_y = (double)(ant_move->end.y - ant_move->start.y) / ((float)lm->speed);
	ant_move->curr.x = ant_move->start.x + step_x * lm->step_counter;
	ant_move->curr.y = ant_move->start.y + step_y * lm->step_counter;
	if (lm->step_counter >= lm->speed)
	{
		ant_move->start = ant_move->end;
		ant_move->start_room = ant_move->end_room;
	}
}

int				loop_ants_move(t_lemin_mlx *lm)
{
	int i;

	put_all_anthill(lm);
	transparent_ants_image(lm);
	i = -1;
	while (++i < lm->lem->number_of_ants)
		set_ant_move(lm, &(lm->ants_move[i]));
	if (lm->step_counter < lm->speed + 2)
		lm->step_counter++;
	if (lm->step_counter == lm->speed + 2 && lm->nonstop == 1)
		lemin_keyhook(47, lm);
	usleep(100);
	draw_ants(lm);
	put_ants_image_to_window(lm);
	return (1);
}
