/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:03:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 18:53:54 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static t_start_end	take_start_end(t_lemin *lem, int i)
{
	t_start_end		res;
	t_edge			e;

	e = lem->edges[i];
	if (e.from == lem->s)
	{
		res.start = e.from;
		res.end = e.to;
	}
	else if (e.to == lem->s)
	{
		res.start = e.to;
		res.end = e.from;
	}
	else if (e.from == lem->t)
	{
		res.start = e.to;
		res.end = e.from;
	}
	else
	{
		res.start = e.from;
		res.end = e.to;
	}
	return (res);
}

static void			*add_edge(t_lemin *lem, int start, int end, int capacity)
{
	t_gedge tmp;

	tmp.to = end;
	tmp.cap = capacity;
	tmp.flow = 0;
	tmp.flow1 = 0;
	ft_dlst_addcontent_back(&(lem->g[start]), &tmp, sizeof(tmp));
	return (lem);
}

static void			add_edges_in_graph(t_lemin *lem, t_start_end se)
{
	add_edge(lem, 2 * se.start, 2 * se.end + 1, 1);
	add_edge(lem, 2 * se.end + 1, 2 * se.start, 0);
	if (se.start != lem->s && se.end != lem->t)
	{
		add_edge(lem, 2 * se.end, 2 * se.start + 1, 1);
		add_edge(lem, 2 * se.start + 1, 2 * se.end, 0);
	}
}

static void			add_connection_edges_in_graph(t_lemin *lem)
{
	int		i;

	i = -1;
	while (++i < lem->count_rooms)
	{
		if (i != lem->s && i != lem->t)
		{
			add_edge(lem, 2 * i + 1, 2 * i, 1);
			add_edge(lem, 2 * i, 2 * i + 1, 0);
		}
	}
}

void				lemin_fill_graph(t_lemin *lem)
{
	int				i;
	t_start_end		se;

	if (!(lem->g = (t_dlist**)ft_memalloc(sizeof(t_dlist*) * lem->size_matrix)))
		finish_prog(lem, -1, -1, NULL);
	i = -1;
	while (++i < lem->count_edges)
	{
		se = take_start_end(lem, i);
		add_edges_in_graph(lem, se);
	}
	add_connection_edges_in_graph(lem);
	lem->s = lem->start_room * 2;
	lem->t = lem->end_room * 2 + 1;
}
