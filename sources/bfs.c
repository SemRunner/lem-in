/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:47:06 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 18:55:39 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		lemin_assign_vectors_bfs(t_lemin *lem)
{
	vector_int_assign(lem->mark, lem->size_matrix, 0);
	vector_int_assign(lem->push, lem->size_matrix, 0);
	vector_int_assign(lem->pred, lem->size_matrix, 0);
	lem->mark[lem->s] = 1;
	lem->pred[lem->s] = lem->s;
	lem->push[lem->s] = INF;
}

static void		bfs_aux(t_lemin *lem, int v, int u, t_queue *q)
{
	lem->mark[v] = 1;
	lem->pred[v] = u;
	qi_push(q, v);
}

int				bfs(t_lemin *lem)
{
	t_queue		q;
	int			u;
	t_dlist		*curr;
	t_gedge		*edg;

	queue_init(&q);
	lemin_assign_vectors_bfs(lem);
	qi_push(&q, lem->s);
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q);
		curr = lem->g[u];
		while (curr != NULL)
		{
			edg = curr->content;
			if (!lem->mark[edg->to] && edg->cap - edg->flow > 0)
			{
				lem->push[edg->to] = MIN(lem->push[u], edg->cap - edg->flow);
				bfs_aux(lem, edg->to, u, &q);
			}
			curr = curr->next;
		}
	}
	qi_del(&q);
	return (lem->mark[lem->t]);
}

int				bfs_ways(t_lemin *lem)
{
	t_queue		q;
	int			u;
	t_dlist		*curr;
	t_gedge		*edg;

	queue_init(&q);
	lemin_assign_vectors_bfs(lem);
	qi_push(&q, lem->s);
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q);
		curr = lem->g[u];
		while (curr != NULL)
		{
			edg = curr->content;
			if (!(lem->mark[edg->to]) && edg->flow1 > 0)
				bfs_aux(lem, edg->to, u, &q);
			curr = curr->next;
		}
	}
	qi_del(&q);
	return (lem->mark[lem->t]);
}
