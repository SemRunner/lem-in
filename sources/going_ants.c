/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   going_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:04:51 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/16 19:17:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		set_ants_to_left_on_ways(t_lemin *l)
{
	int		ants_left;
	int		step;
	int		i;

	ants_left = l->number_of_ants;
	step = 0;
	while (ants_left > 0)
	{
		step++;
		i = -1;
		while (++i < l->count_ways && ants_left > 0)
		{
			if (count_bandwidth(l->way_length[i], step) > 0)
			{
				l->ants_left_on_ways[i]++;
				ants_left--;
			}
		}
	}
}

static void		add_ant_to_way(t_lemin *l, int i, int j, int *ant_counter)
{
	if (l->ants_left_on_ways[i] != 0)
	{
		l->ants_left_on_ways[i]--;
		(*ant_counter)++;
		l->ants_on_ways[i][j - 1] = *ant_counter;
	}
}

static void		going_on_ways(t_lemin *l, int *ants_left, int *ant_counter)
{
	int		i;
	int		j;

	i = -1;
	while (++i < l->count_ways && *ants_left != 0)
	{
		j = -1;
		while (l->ways[i][++j] != l->start_room)
		{
			if (j == 0)
			{
				if (l->ants_on_ways[i][j] != 0)
				{
					l->ants_on_ways[i][j] = 0;
					*ants_left = *ants_left - 1;
				}
			}
			else
			{
				l->ants_on_ways[i][j - 1] = l->ants_on_ways[i][j];
				l->ants_on_ways[i][j] = 0;
			}
		}
		add_ant_to_way(l, i, j, ant_counter);
	}
}

static void		print_ants_on_ways(t_lemin *l)
{
	int		i;
	int		j;
	char	flag;
	char	space[2];

	flag = 0;
	space[1] = '\0';
	j = -1;
	while (++j < l->count_rooms)
	{
		i = -1;
		while (++i < l->count_ways)
		{
			if (l->ants_on_ways[i][j] != 0)
			{
				space[0] = flag == 1 ? ' ' : '\0';
				ft_printf("%sL%d-%s", space, l->ants_on_ways[i][j],
						(l->rooms[l->ways[i][j]])->name);
				flag = 1;
			}
		}
	}
	if (flag)
		ft_printf("\n");
}

void			going_ants(t_lemin *l)
{
	int		ants_left;
	int		ant_counter;

	if (l->count_ways == 0)
		return ;
	if (!(l->ants_left_on_ways = (int*)ft_memalloc(sizeof(int) * l->count_ways)))
		finish_prog(l, -1, -1, NULL);
	set_ants_to_left_on_ways(l);
	ants_left = l->number_of_ants;
	ant_counter = 0;
	while (ants_left != 0)
	{
		going_on_ways(l, &ants_left, &ant_counter);
		print_ants_on_ways(l);
	}
}
