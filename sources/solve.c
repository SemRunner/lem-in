/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:58:38 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:54:46 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		add_in_flow(t_lemin *lem, int u, int v, int add)
{
	t_dlist *curr;
	t_gedge *edg;

	curr = lem->g[u];
	while (curr != NULL)
	{
		edg = (t_gedge*)curr->content;
		if (edg->to == v)
		{
			edg->flow += add;
			return ;
		}
		curr = curr->next;
	}
}

static void		set_flow(t_lemin *lem)
{
	int u;
	int v;
	int add;
	int flow;

	flow = 0;
	add = lem->push[lem->t];
	v = lem->t;
	u = lem->pred[v];
	while (v != lem->s)
	{
		add_in_flow(lem, u, v, add);
		add_in_flow(lem, v, u, -add);
		v = u;
		u = lem->pred[v];
	}
	flow += add;
	lem->max_flow += flow;
}

static void		swap_ways(t_lemin *l)
{
	int **tmp;
	int *tmp1;
	int tmp2;

	tmp = l->prev_ways;
	l->prev_ways = l->ways;
	l->ways = tmp;
	tmp1 = l->prev_way_length;
	l->prev_way_length = l->way_length;
	l->way_length = tmp1;
	tmp2 = l->prev_count_ways;
	l->prev_count_ways = l->count_ways;
	l->count_ways = tmp2;
	tmp2 = l->prev_count_steps;
	l->prev_count_steps = l->count_steps;
	l->count_steps = tmp2;
}

void			debug_print_solve(t_lemin *l)
{
	ft_printf("%w#--------------\n", 2);
	ft_printf("%w#way      (num_ways %2d) (step % 3d): ", 2,
				l->count_ways, l->count_steps);
	vector_int_print(l->way_length, l->count_ways, 2);
	ft_printf("%w#way prev (num_ways %2d) (step % 3d): ", 2,
				l->prev_count_ways, l->prev_count_steps);
	vector_int_print(l->prev_way_length, l->prev_count_ways, 2);
}

void			solve(t_lemin *l)
{
	while (bfs(l))
	{
		set_flow(l);
		calculate_ways(l);
		if (LEMIN_DEBUG)
			debug_print_solve(l);
		if (l->prev_count_ways == 0)
		{
			if (l->number_of_ants == 1)
				return ;
			else
				swap_ways(l);
		}
		else if (l->count_steps < l->prev_count_steps)
			swap_ways(l);
	}
	swap_ways(l);
}
