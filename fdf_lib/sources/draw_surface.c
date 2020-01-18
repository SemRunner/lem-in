/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:10:22 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/03 00:09:39 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_surface(t_mlx *m, int not_black)
{
	int		i;
	int		j;
	int		n1;
	int		n2;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			n1 = i * m->map_x + j;
			n2 = i * m->map_x + j + 1;
			if (j + 1 < m->map_x)
				putline(m, m->map_points[n1],
						m->map_points[n2], not_black);
			n2 = (i + 1) * m->map_x + j;
			if (i + 1 < m->map_y)
				putline(m, m->map_points[n1],
						m->map_points[n2], not_black);
			j++;
		}
		i++;
	}
}
