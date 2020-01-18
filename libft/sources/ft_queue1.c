/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:13:10 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:15:49 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				qi_pop(t_queue *queue)
{
	int		ret;
	t_dlist	*tmp_lst;

	if (queue->len == 0)
		return (NO_DEFINE);
	else
	{
		ret = int_content(queue->bottom);
		tmp_lst = queue->bottom;
		if (queue->len == 1)
		{
			queue->top = NULL;
			queue->bottom = NULL;
		}
		else
		{
			queue->bottom = queue->bottom->prev;
			queue->bottom->next = NULL;
			queue->top->prev = queue->bottom;
		}
		queue->len--;
		ft_dlstdel(&tmp_lst, NULL);
		return (ret);
	}
}

int				qi_front(t_queue *queue)
{
	if (queue->len == 0)
		return (NO_DEFINE);
	return (int_content(queue->bottom));
}

int				qi_back(t_queue *queue)
{
	if (queue->len == 0)
		return (NO_DEFINE);
	return (int_content(queue->top));
}

int				qi_empty(t_queue *queue)
{
	if (queue->len == 0)
		return (1);
	else
		return (0);
}

void			qi_print(t_queue *q)
{
	t_dlist		*curr;

	if (q->len == 0)
		ft_printf("queue empty\n");
	curr = q->top;
	while (curr != NULL)
	{
		ft_printf("%d ", int_content(curr));
		curr = curr->next;
	}
	ft_printf("\n");
}
