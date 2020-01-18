/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlemin_mlx_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:23:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:15:51 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"

void			finish_all(t_lemin_mlx *lm, int res)
{
	if (lm->lem != NULL)
		finish_prog(lm->lem, -10, -1, NULL);
	if (lm->ant_im != NULL)
		mlx_destroy_image(lm->m->ptr, lm->ant_im);
	if (lm->m != NULL)
		tmlx_destroy(lm->m, -10);
	if (lm->ants_move != NULL)
		ft_memdel((void**)lm->ants_move);
	exit(res);
}

void			tlemin_mlx_initialize(t_lemin_mlx *lm)
{
	lm->m = NULL;
	lm->lem = NULL;
	lm->ant_im = NULL;
	lm->size_ant_im = 0;
	lm->ants_move = NULL;
	lm->count_steps = 0;
	lm->step_counter = 0;
	lm->nonstop = 0;
	lm->speed = 8;
	lm->show_room_numbers = 1;
	lm->show_not_use_edges = 1;
	lm->show_interm_rooms = 1;
	lm->show_ways = 1;
	lm->time_draw_anthill = 0.0;
	lm->in_move = 0;
	lm->mleft_pressed = 0;
	lm->mright_pressed = 0;
}
