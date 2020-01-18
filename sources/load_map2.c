/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/16 19:14:49 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

void			load_number_of_ants(t_lemin *lemin, int fd)
{
	char	*line;
	int		res;

	line = NULL;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == '#')
			ft_memdel((void**)&line);
		else if (ft_isint(line))
		{
			lemin->number_of_ants = ft_atoi(line);
			ft_memdel((void**)&line);
			if (lemin->number_of_ants <= 0)
				finish_prog(lemin, -1, fd, NULL);
			else if (!(lemin->ants_moving = (t_dlist**)
					ft_memalloc(sizeof(t_dlist*) * lemin->number_of_ants)))
				finish_prog(lemin, -1, fd, NULL);
			break ;
		}
		else
			finish_prog(lemin, -1, fd, NULL);
	}
	ft_memdel((void**)&line);
	if (res < 0)
		finish_prog(lemin, -1, fd, NULL);
}

void			check_data(t_lemin *l)
{
	if (errno != 0)
		finish_prog(l, -1, -1, NULL);
	if (l->number_of_ants <= 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_rooms == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_edges == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->start_room == -1 || l->end_room == -1)
		finish_prog(l, -1, -1, NULL);
}

void			set_numbers_rooms(t_lemin *lemin)
{
	int			i;

	i = -1;
	while (++i < lemin->count_rooms)
	{
		lemin->rooms[i]->number = i;
		if (lemin->rooms[i]->start_end_flag == 1)
			lemin->start_room = i;
		else if (lemin->rooms[i]->start_end_flag == 2)
			lemin->end_room = i;
	}
}
