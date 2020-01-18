/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room_links_props.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 00:10:36 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/03 00:10:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void			print_room_property(t_dlist *lst)
{
	ft_printf("name=%s, number=%d, x=%d, y=%d, z=%d, flag=%d\n",
		((t_room*)(lst->content))->name,
		((t_room*)(lst->content))->number, ((t_room*)(lst->content))->x,
		((t_room*)(lst->content))->y, ((t_room*)(lst->content))->z,
		((t_room*)(lst->content))->start_end_flag);
}

void			print_all_rooms_property(t_dlist *lst)
{
	t_dlist		*curr;

	curr = lst;
	while (curr != NULL)
	{
		print_room_property(curr);
		curr = curr->next;
	}
}

void			print_links(t_dlist *lst)
{
	ft_printf("room=%s - room=%s\n", ((t_room_ways*)(lst->content))->start_room,
		((t_room_ways*)(lst->content))->end_room);
}

void			print_all_links(t_dlist *lst)
{
	t_dlist		*curr;

	curr = lst;
	while (curr != NULL)
	{
		print_links(curr);
		curr = curr->next;
	}
}

void			print_all_edges(t_lemin *lemin)
{
	int		i;
	t_edge	e;

	i = 0;
	while (i < lemin->count_edges)
	{
		e = lemin->edges[i];
		ft_printf("edge[%d]: from=%d, to=%d, cap=%d, cost=%d\n",
				i, e.from, e.to, e.capacity, e.cost);
		i++;
	}
}
