/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:30:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 18:01:13 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_mlx.h"
#include "fdf.h"

int			mouse_move(int x, int y, t_lemin_mlx *lm)
{
	if (!fdf_in_frontiers(x, y, lm->m))
		return (1);
	if (lm->m->mright_pressed == 1 || lm->m->mleft_pressed == 1)
	{
		remove_anthill_from_image(lm);
		fdf_mouse_move(x, y, lm->m);
		put_anthill_to_image(lm);
		loop_ants_move(lm);
	}
	else
		fdf_mouse_move(x, y, lm->m);
	return (1);
}

int			mouse_press(int key, int x, int y, t_lemin_mlx *lm)
{
	if (!fdf_in_frontiers(x, y, lm->m))
		return (1);
	if (key == FDF_SCROLL_U || key == FDF_SCROLL_D)
	{
		remove_anthill_from_image(lm);
		fdf_mouse_press(key, x, y, lm->m);
		put_anthill_to_image(lm);
		loop_ants_move(lm);
	}
	else if (key == FDF_MOUSE_RIGHT || key == FDF_MOUSE_LEFT)
		fdf_mouse_press(key, x, y, lm->m);
	return (1);
}

int			mouse_release(int key, int x, int y, t_lemin_mlx *lm)
{
	lm->in_move = 0;
	if (key == FDF_MOUSE_RIGHT || key == FDF_MOUSE_LEFT)
		fdf_mouse_release(key, x, y, lm->m);
	return (1);
}
