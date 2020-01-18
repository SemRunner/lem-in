/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_figures_box.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:15:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:57:03 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void				putbox(t_mlx *m, t_point center, int size, int not_black)
{
	t_point start;
	t_point end;

	start = center;
	end = center;
	start.x -= size / 2;
	start.y -= size / 2;
	end.x += size / 2;
	end.y -= size / 2;
	putline(m, start, end, not_black);
	start.x += size;
	start.y += size;
	putline(m, start, end, not_black);
	end.x -= size;
	end.y += size;
	putline(m, start, end, not_black);
	start.x -= size;
	start.y -= size;
	putline(m, start, end, not_black);
}

void				putbox_full(t_mlx *m, t_point center, int size,
								int not_black)
{
	while (size)
		putbox(m, center, size--, not_black);
}
