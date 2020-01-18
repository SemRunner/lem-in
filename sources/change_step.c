/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:23:47 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:23:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"

static void		set_room_in_ants_move(t_lemin_mlx *lm, t_ant_move *am, int i)
{
	if (am->step == lm->lem->current_step)
	{
		lm->ants_move[i].start_room = lm->ants_move[i].end_room;
		lm->ants_move[i].start = lm->m->map_points[lm->ants_move[i].start_room];
		lm->ants_move[i].end_room = am->to;
		lm->ants_move[i].end = lm->m->map_points[am->to];
		lm->ants_move[i].curr = lm->m->map_points[lm->ants_move[i].start_room];
	}
}

void			set_ants_to_rooms_on_step(t_lemin_mlx *lm)
{
	int			i;
	t_dlist		*curr;
	int			start_step;
	int			end_step;

	start_step = -1;
	end_step = -1;
	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		curr = lm->lem->ants_moving[i];
		if (curr != NULL)
			start_step = ((t_ant_move*)(curr->content))->step;
		while (curr != NULL)
		{
			set_room_in_ants_move(lm, curr->content, i);
			end_step = ((t_ant_move*)(curr->content))->step;
			curr = curr->next;
		}
		if (lm->lem->current_step < start_step)
			lm->ants_move[i].end_room = lm->lem->start_room;
		else if (lm->lem->current_step > end_step)
			lm->ants_move[i].end_room = lm->lem->end_room;
	}
	lm->step_counter = 0;
}
