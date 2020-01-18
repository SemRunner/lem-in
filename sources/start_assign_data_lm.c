/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assign_data_lm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:16:37 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:08:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"
#include "fdf.h"

void			create_ant_draw_move(t_lemin_mlx *lm)
{
	int		i;

	if (!(lm->ants_move = (t_ant_draw_move*)
		ft_memalloc(sizeof(t_ant_draw_move) * lm->lem->number_of_ants)))
		finish_all(lm, -1);
	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		lm->ants_move[i].start_room = lm->lem->start_room;
		lm->ants_move[i].end_room = lm->lem->start_room;
	}
}
