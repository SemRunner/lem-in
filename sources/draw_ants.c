/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:56:34 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:09:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"

void			draw_ant(t_lemin_mlx *lm, int i, t_point p)
{
	i = 0;
	put_ant_on_ants_image(lm, p.x, p.y);
}

static void		put_count_of_ants(t_lemin_mlx *lm, int count_in_start,
									int count_in_end)
{
	t_point p;
	char	str[20];

	p = lm->m->map_points[lm->lem->start_room];
	str[0] = '\0';
	ft_printf("%y(%d)", str, count_in_start);
	mlx_string_put(lm->m->ptr, lm->m->win, p.x + (lm->size_ant_im) / 2 + 5,
										p.y - (lm->size_ant_im) / 2 - 12,
										0x55FF,
										str);
	str[0] = '\0';
	p = lm->m->map_points[lm->lem->end_room];
	ft_printf("%y(%d)", str, count_in_end);
	mlx_string_put(lm->m->ptr, lm->m->win, p.x + (lm->size_ant_im) / 2 + 5,
										p.y - (lm->size_ant_im) / 2 - 12,
										0x00FF00,
										str);
}

void			draw_ants(t_lemin_mlx *lm)
{
	int		i;
	int		count_in_start;
	int		count_in_end;

	count_in_start = 0;
	count_in_end = 0;
	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		if (lm->ants_move[i].start_room == lm->lem->start_room &&
			lm->ants_move[i].end_room == lm->lem->start_room)
		{
			if (count_in_start++ != 0)
				continue ;
		}
		if (lm->ants_move[i].start_room == lm->lem->end_room &&
			lm->ants_move[i].end_room == lm->lem->end_room)
		{
			if (count_in_end++ != 0)
				continue ;
		}
		draw_ant(lm, i, lm->ants_move[i].curr);
	}
	put_count_of_ants(lm, count_in_start, count_in_end);
}
