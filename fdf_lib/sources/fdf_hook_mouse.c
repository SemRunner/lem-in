/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:11:36 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 17:44:45 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int			fdf_in_frontiers(int x, int y, t_mlx *m)
{
	if (x < 0 || x >= m->width)
		return (0);
	else if (y < 0 || y >= m->height)
		return (0);
	return (1);
}

int			fdf_mouse_move(int x, int y, t_mlx *m)
{
	int		dx;
	int		dy;

	if (!fdf_in_frontiers(x, y, m))
		return (1);
	if (m->mright_pressed == 1)
	{
		dx = x - m->mouse_x;
		dy = y - m->mouse_y;
		if (y < m->height / 2)
			m->z_angle -= (atan(dx) / 15.0) * 180.0 / M_PI;
		else
			m->z_angle += (atan(dx) / 15.0) * 180.0 / M_PI;
		m->z_angle %= 360;
		m->x_angle -= (atan(dy) / 45.0) * 180.0 / M_PI;
		m->x_angle %= 360;	
	}
	else if (m->mleft_pressed == 1)
	{
		dx = x - m->mouse_x;
		dy = y - m->mouse_y;
		m->camera_x += dx;
		m->camera_y += dy;

	}
	m->mouse_x = x;
	m->mouse_y = y;
	return (1);
}

int			fdf_mouse_press(int key, int x, int y, t_mlx *m)
{
	if (!fdf_in_frontiers(x, y, m))
		return (1);
	m->mouse_x = x;
	m->mouse_y = y;
	if (key == FDF_SCROLL_D)
		keyhooks(126, m);
	else if (key == FDF_SCROLL_U)
		keyhooks(125, m);
	else if (key == FDF_MOUSE_RIGHT)
	{
		m->in_move = 1;
		m->mright_pressed = 1;
	}
	else if (key == FDF_MOUSE_LEFT)
	{
		m->in_move = 1;
		m->mleft_pressed = 1;
	}
	return (1);
}

int			fdf_mouse_release(int key, int x, int y, t_mlx *m)
{
	m->in_move = 0;
	if (!fdf_in_frontiers(x, y, m))
		return (1);
	if (key == FDF_MOUSE_RIGHT)
		m->mright_pressed = 0;
	else if (key == FDF_MOUSE_LEFT)
		m->mleft_pressed = 0;
	return (1);
}
