/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:24:32 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 15:24:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawpoint(t_mlx *m, int i)
{
	putpixel(m, m->map_points[i].x, m->map_points[i].y, m->map_points[i].color);
}

t_point			get_point_to_draw(t_mlx *m, int i)
{
	return (m->map_points[i]);
}
