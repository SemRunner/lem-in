/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ant_im.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:59:12 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:31:47 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"

void			load_ant_im(t_lemin_mlx *lm)
{
	if (lm->ant_im)
		mlx_destroy_image(lm->m->ptr, lm->ant_im);
	if (lm->size_ant_im == 10)
		lm->ant_im = mlx_xpm_file_to_image(lm->m->ptr,
			"./images/white_ant_10_10.xpm",
			&(lm->size_ant_im), &(lm->size_ant_im));
	else if (lm->size_ant_im == 20)
		lm->ant_im = mlx_xpm_file_to_image(lm->m->ptr,
			"./images/white_ant_20_20.xpm",
			&(lm->size_ant_im), &(lm->size_ant_im));
	else if (lm->size_ant_im == 30)
		lm->ant_im = mlx_xpm_file_to_image(lm->m->ptr,
		"./images/white_ant_30_30.xpm",
		&(lm->size_ant_im), &(lm->size_ant_im));
	else
		lm->ant_im = mlx_xpm_file_to_image(lm->m->ptr,
		"./images/white_ant_40_40.xpm",
		&(lm->size_ant_im), &(lm->size_ant_im));
	lm->data_ant_im = (int *)mlx_get_data_addr(lm->ant_im,
		&(lm->m->bits_pixel), &(lm->size_line_ant_im), &(lm->m->endian));
}

void			start_load_ant_im(t_lemin_mlx *lm)
{
	if (lm->lem->count_rooms < 20)
		lm->size_ant_im = 40;
	else if (lm->lem->count_rooms < 100)
		lm->size_ant_im = 30;
	else if (lm->lem->count_rooms < 400)
		lm->size_ant_im = 20;
	else
		lm->size_ant_im = 10;
	load_ant_im(lm);
}
