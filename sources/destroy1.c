/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:22:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:34:26 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "stdio.h"

void		destroy_room(void *room, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&(((t_room*)room)->name));
}

void		destroy_ant_move(void *ant_move, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&(((t_ant_move*)ant_move)->to_name));
}

void		destroy_way(void *room_ways, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&((t_room_ways*)room_ways)->start_room);
	ft_memdel((void**)&((t_room_ways*)room_ways)->end_room);
}
