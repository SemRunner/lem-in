/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_keyhooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:58:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 18:09:32 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"
#include <time.h>

int		keyhook_move_ants(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 43 && lm->lem->current_step > 0)
		lm->lem->current_step--;
	else if (keycode == 44)
		lm->lem->current_step = 0;
	else if (keycode == 47 && lm->lem->current_step < lm->lem->max_step)
		lm->lem->current_step += 1;
	else if (keycode == 46)
		lm->nonstop = (lm->nonstop + 1) % 2;
	else if (keycode == 30 && lm->speed > 2)
		lm->speed /= 2;
	else if (keycode == 33 && lm->speed < 16)
		lm->speed *= 2;
	else
		return (0);
	return (1);
}

int		keycode_change_size_room(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 42 && lm->size_ant_im < 40)
		lm->size_ant_im += 10;
	else if (keycode == 39 && lm->size_ant_im > 10)
		lm->size_ant_im -= 10;
	else
		return (0);
	return (1);
}

int		keycode_names_room(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 35)
		lm->show_room_numbers = (lm->show_room_numbers + 1) % 2;
	else if (keycode == 31)
		lm->show_not_use_edges = (lm->show_not_use_edges + 1) % 2;
	else if (keycode == 34)
		lm->show_interm_rooms = (lm->show_interm_rooms + 1) % 2;
	else if (keycode == 45)
		lm->show_ways = (lm->show_ways + 1) % 3;
	else
		return (0);
	return (1);
}

int		lemin_keyhook(int keycode, void *lm)
{
	if (keycode == 12 || keycode == 53)
		finish_all((t_lemin_mlx*)lm, -10);
	if (check_keyhooks_fdf(keycode) || keycode == 39 || keycode == 42 ||
		keycode == 35 || keycode == -1 || keycode == 31 || keycode == 34 ||
		keycode == 45)
	{
		remove_anthill_from_image(lm);
		keyhooks(keycode, ((t_lemin_mlx*)lm)->m);
		keycode_names_room(keycode, ((t_lemin_mlx*)lm));
		if (keycode_change_size_room(keycode, ((t_lemin_mlx*)lm)))
			load_ant_im(lm);
		put_anthill_to_image(lm);
		loop_ants_move(lm);
	}
	if (keyhook_move_ants(keycode, ((t_lemin_mlx*)lm)))
		set_ants_to_rooms_on_step(lm);
	if (keycode == -1)
		set_ants_to_start((t_lemin_mlx*)lm);
	return (1);
}
