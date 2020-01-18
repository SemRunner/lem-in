/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:40:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 18:28:45 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

int		keyhook1(int keycode, t_mlx *m)
{
	if (keycode == 126)
	{
		if (m->zoom_coef < 40 && m->h_coef < 80)
			calc_hzoom(m, 1);
	}
	else if (keycode == 125)
	{
		if (m->zoom_coef > 1 && m->h_coef > 1)
			calc_hzoom(m, -1);
	}
	else if (keycode == 123)
		m->z_angle -= m->rotate_prec;
	else if (keycode == 124)
		m->z_angle += m->rotate_prec;
	else if (keycode == 13)
		m->x_angle -= m->rotate_prec;
	else if (keycode == 1)
		m->x_angle += m->rotate_prec;
	else
		return (0);
	return (1);
}

int		keyhook2(int keycode, t_mlx *m)
{
	if (keycode == 0)
		m->y_angle -= m->rotate_prec;
	else if (keycode == 2)
		m->y_angle += m->rotate_prec;
	else if (keycode == 18)
	{
		if (m->projection_type == 4)
		{
			m->x_angle -= 60;
			m->z_angle += 45;
		}
		m->projection_type = 0;
	}
	else if (keycode == 19)
	{
		if (m->projection_type == 4)
		{
			m->x_angle -= 60;
			m->z_angle += 45;
		}
		m->projection_type = 1;
	}
	else if (keycode == 20)
	{
		if (m->projection_type == 4)
		{
			m->x_angle -= 60;
			m->z_angle += 45;
		}
		m->projection_type = 2;
	}
	else if (keycode == 21)
	{
		if (m->projection_type == 4)
		{
			m->x_angle -= 60;
			m->z_angle += 45;
		}
		m->projection_type = 3;
	}
	else if (keycode == FDF_KEY_5)
	{
		if (m->projection_type != 4)
		{
			m->x_angle += 60;
			m->z_angle -= 45;
		}
		m->projection_type = 4;
	}
	else if (keycode == FDF_KEY_6)
		m->angle_projection_type =
			++(m->angle_projection_type) % 3;
	else if (keycode == 6)
		m->type_color_spectrum = ++(m->type_color_spectrum) % 2;
	else
		return (0);
	return (1);
}

int		keyhook3(int keycode, t_mlx *m)
{
	if (keycode == 53 || keycode == 12)
		tmlx_destroy((t_mlx*)m, 0);
	else if (keycode == FDF_KEY_X)
		reset_map((t_mlx*)m);
	else if (keycode == 32)
		m->camera_y += 40 * m->zoom;
	else if (keycode == 38)
		m->camera_y -= 40 * m->zoom;
	else if (keycode == 4)
		m->camera_x += 40 * m->zoom;
	else if (keycode == 40)
		m->camera_x -= 40 * m->zoom;
	else if (keycode == 3)
	{
		m->h_coef -= m->h_coef > 1 ? 1 : 0;
		calc_hzoom(m, 0);
	}
	else if (keycode == 15)
	{
		m->h_coef += m->h_coef < 80 ? 1 : 0;
		calc_hzoom(m, 0);
	}
	else
		return (0);
	return (1);
}

int		check_keyhooks_fdf(int k)
{
	if (k == 126 || k == 125 || k == 123 || k == 124 || k == 13 || k == 1 ||
		k == 0 || k == 2 || k == 18 || k == 19 || k == 20 || k == 21 ||
		k == 23 || k == 6 || k == 53 || k == 7 || k == 32 || k == 38 ||
		k == 4 || k == 40 || k == 3 || k == 15 || k == 7 || k == 12)
		return (1);
	return (0);
}

int		keyhooks(int keycode, t_mlx *m)
{
	m->prev_ang_proj_type = m->angle_projection_type;
	m->prev_proj_type = m->projection_type;
	return (keyhook1(keycode, (t_mlx*)m) ||
			keyhook2(keycode, (t_mlx*)m) ||
			keyhook3(keycode, (t_mlx*)m));
}
