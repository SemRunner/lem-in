/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 18:31:32 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>
#include <unistd.h>
#include "ft_timer.h"

int				test_cmp(int *a, int *b)
{
	if (*a > *b)
		return (1);
	else if (*a == *b)
		return (0);
	else
		return (-1);
}

void			set_start_conditions(t_lemin_mlx *lm)
{
	if (lm->lem->count_rooms > 100)
	{
		lm->show_room_numbers = 0;
		lm->show_interm_rooms = 0;
	}
	if (lm->lem->count_all_edges_moving > 1000000)
	{
		lm->show_ways = 0;
	}
}

void			start_initialize(t_lemin_mlx *lm, t_lemin *l, t_mlx *m)
{
	tlemin_initialize(l);
	tmlx_initialize(m, WIDTH, HEIGHT);
	tlemin_mlx_initialize(lm);
	errno = 0;
	l->is_visu = 1;
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	t_mlx		m;
	t_lemin_mlx	lm;

	start_initialize(&lm, &lemin, &m);
	reset_all_timers();
	errno = 0;

	load_and_prepare_lemin(&lemin, argc, argv);
	set_num_rooms_to_ant_moves(&lemin);
	load_anthill_to_map_points(&m, &lemin);
	calc_parameter_maps(&m);
	make_map_points(&m);
	if (lemin.is_room_color == 0)
		set_mappoints_color(&m);
	lm.m = &m;
	lm.lem = &lemin;
	if (tmlx_create_mlx(&m, "lemin") == 0)
		finish_all(&lm, -1);
	create_ant_draw_move(&lm);
	start_load_ant_im(&lm);
	set_start_conditions(&lm);
	initialize_ants_image(&lm);
	lemin_keyhook(FDF_KEY_5, (void*)&lm);
	mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	mlx_loop_hook(m.ptr, loop_ants_move, (void*)&lm);
	mlx_hook(m.win, 6, 0, mouse_move, &lm);
	mlx_hook(m.win, 4, 0, mouse_press, &lm);
	mlx_hook(m.win, 5, 0, mouse_release, &lm);
	mlx_loop(m.ptr);
	finish_prog(&lemin, 0, -1, NULL);
}
