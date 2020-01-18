/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:59:28 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 19:01:39 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void			copy_flow_to_flow1(t_lemin *lem)
{
	int			i;
	t_dlist		*curr;
	t_gedge		*edg;

	i = -1;
	while (++i < lem->size_matrix)
	{
		curr = lem->g[i];
		while (curr != NULL)
		{
			edg = curr->content;
			edg->flow1 = edg->flow;
			curr = curr->next;
		}
	}
}

static t_gedge		*g_edg(t_lemin *lem, int u, int v)
{
	t_dlist *curr;

	curr = lem->g[u];
	while (curr != NULL)
	{
		if (((t_gedge*)curr->content)->to == v)
			return ((t_gedge*)curr->content);
		curr = curr->next;
	}
	return (NULL);
}

static void			count_steps(t_lemin *l)
{
	int i;
	int steps;
	int count_ants;

	if (l->count_ways == 0)
		return ;
	count_ants = 0;
	steps = 1;
	while (1)
	{
		i = -1;
		while (++i < l->count_ways)
		{
			if (steps + 1 - l->way_length[i] > 0)
				count_ants++;
		}
		if (count_ants >= l->number_of_ants)
			break ;
		steps++;
	}
	l->count_steps = steps;
}

static void			calc_ways_aux(t_lemin *l, int *u, int *v)
{
	if (*u / 2 == *v / 2)
	{
		g_edg(l, *u, *v)->flow1 = 0;
		*v = *u;
		*u = l->pred[*v];
	}
	g_edg(l, *u, *v)->flow1 = 0;
	*v = *u;
	*u = l->pred[*v];
}

void				calculate_ways(t_lemin *l)
{
	int		i;
	int		j;
	int		v;
	int		u;

	copy_flow_to_flow1(l);
	l->count_ways = l->max_flow;
	i = -1;
	while (++i < l->max_flow)
	{
		bfs_ways(l);
		v = l->t;
		u = l->pred[v];
		j = 0;
		while (v != l->s)
		{
			l->ways[i][j++] = v / 2;
			calc_ways_aux(l, &u, &v);
		}
		l->ways[i][j] = l->start_room;
		l->way_length[i] = j;
	}
	count_steps(l);
}
