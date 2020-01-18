/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:22:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:35:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "stdio.h"

static void		del_g(t_lemin *l)
{
	int		i;

	i = -1;
	while (++i < l->size_matrix)
		ft_dlstdel(&(l->g[i]), NULL);
	free(l->g);
	l->g = NULL;
}

void			del_ants_moving(t_lemin *l)
{
	int		i;

	if (l->ants_moving == NULL)
		return ;
	i = 0;
	while (i < l->number_of_ants)
	{
		ft_dlstdel(&(l->ants_moving[i]), destroy_ant_move);
		i++;
	}
	free(l->ants_moving);
	l->ants_moving = NULL;
}

void			lemin_destroy(t_lemin *lemin)
{
	ft_dlstdel(&(lemin->list_rooms), destroy_room);
	ft_dlstdel(&(lemin->room_ways), destroy_way);
	ft_memdel((void**)&lemin->edges);
	if (lemin->rooms != NULL)
	{
		free(lemin->rooms);
		lemin->rooms = NULL;
	}
	ft_delmatrix((void***)&(lemin->ants_on_ways), lemin->max_ways);
	ft_delmatrix((void***)&(lemin->ways), lemin->max_ways);
	ft_delmatrix((void***)&(lemin->prev_ways), lemin->max_ways);
	ft_delmatrix((void***)&(lemin->ants_moving), lemin->number_of_ants);
	ft_memdel((void**)&lemin->way_length);
	ft_memdel((void**)&lemin->prev_way_length);
	ft_memdel((void*)&lemin->ants_left_on_ways);
	if (lemin->g != NULL)
		del_g(lemin);
	ft_memdel((void**)&lemin->push);
	ft_memdel((void**)&lemin->mark);
	ft_memdel((void**)&lemin->pred);
	free(lemin->rooms);
	lemin->rooms = NULL;
}

void			finish_prog(t_lemin *l, int res, int fd, char **line)
{
	lemin_destroy(l);
	ft_memdel((void**)line);
	if (fd > 0)
		close(fd);
	if (res == -1)
	{
		ft_printf("ERROR\n");
		exit(res);
	}
	if (res == -10)
		exit(res);
}
