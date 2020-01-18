/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_map_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 20:51:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				make_map_points(t_mlx *m)
{
	double	shift_x;
	double	shift_y;
	double	step;
	int		i;

	step = (double)(m->width) / (double)(m->map_x + 1) <
			(double)(m->height) / (double)(m->map_y + 1) ?
			(double)(m->width) / (double)(m->map_x + 1) :
			(double)(m->height) / (double)(m->map_y + 1);
	step *= m->zoom;
	shift_x = ((double)m->width - ((double)m->map_x * step)) / 2.0;
	shift_y = ((double)m->height - ((double)m->map_y * step)) / 2.0;
	i = -1;
	while (++i < m->quantity_points)
	{
		m->map_points[i].x = shift_x + step * m->map_points[i].x0;
		m->map_points[i].y = shift_y + step * m->map_points[i].y0;
		m->map_points[i].z = m->map_points[i].z0 * m->h;
	}
	rotate_points(m);
	projection_points(m);
}

void				calc_parameter_maps(t_mlx *m)
{
	int i;

	m->max_h = m->map_points[0].z0;
	m->min_h = m->map_points[0].z0;
	m->map_x = m->map_points[0].x0;
	m->map_y = m->map_points[0].y0;
	i = 0;
	while (i < m->quantity_points)
	{
		if (m->max_h < m->map_points[i].z0)
			m->max_h = m->map_points[i].z0;
		if (m->min_h > m->map_points[i].z0)
			m->min_h = m->map_points[i].z0;
		if (m->map_x < m->map_points[i].x0)
			m->map_x = m->map_points[i].x0;
		if (m->map_y < m->map_points[i].y0)
			m->map_y = m->map_points[i].y0;
		i++;
	}
}
