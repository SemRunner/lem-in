/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:28:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 21:38:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		print_rooms_anthill(t_lemin *l)
{
	t_dlist		*curr;
	t_room		*room;

	curr = l->list_rooms;
	while (curr != NULL)
	{
		room = curr->content;
		if (room->start_end_flag == 1)
			ft_printf("##start\n");
		else if (room->start_end_flag == 2)
			ft_printf("##end\n");
		ft_printf("%s %d %d", room->name, room->x, room->y);
		if (room->z != NO_DEFINE)
		{
			ft_printf(" %d", room->z);
			if (room->color != NO_DEFINE)
				ft_printf(" 0x%x", room->color);
		}
		ft_printf("\n");
		curr = curr->next;
	}
}

static void		print_ways_anthill(t_lemin *l)
{
	t_dlist		*curr;
	t_room_ways	*way;

	curr = l->room_ways;
	while (curr != NULL)
	{
		way = curr->content;
		ft_printf("%s-%s\n", way->start_room, way->end_room);
		curr = curr->next;
	}
}

void			print_anthill(t_lemin *l)
{
	ft_printf("%d\n", l->number_of_ants);
	print_rooms_anthill(l);
	print_ways_anthill(l);
	ft_printf("\n");
}
