/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:01:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:01:26 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			check_data(t_lemin *l)
{
	if (l->number_of_ants <= 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_rooms == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_edges == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->start_room == -1 || l->end_room == -1)
		finish_prog(l, -1, -1, NULL);
}
