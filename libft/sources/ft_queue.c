/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:13:10 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:16:44 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** queue on dlist
** elements added in back of the queue
** qi_push - added elements to the back of the queue (to bottom)
** qi_back - return content of last element of the queue
** last element of queue = queue->bottom
** qi_front - return content of first element of the queue
** first element of queue = queue->top
** hmm.. need to change names: bottom -> back, top -> front
** qi_pop - return content of front of the queue and delete element.
** so:
**		pop this el-t				push el-t here
**		 |							 |
**		1st - 2nd - 3rd - 4th - 5th ...
**		 |						 |
**		qi_front				qi_back
**		queue->top				queue->bottom
**		top->next = 2nd el-t
**		bottom->prev = 4th el-t
*/

void			del_intcontent(void *content, size_t size)
{
	if (size == 0 && size != 0)
		return ;
	ft_memdel((void**)&content);
}

int				int_content(t_dlist *list)
{
	if (list != NULL)
		return (*(int*)(list->content));
	else
		return (NO_DEFINE);
}

void			queue_init(t_queue *queue)
{
	queue->len = 0;
	queue->top = NULL;
	queue->bottom = NULL;
}

void			qi_del(t_queue *queue)
{
	if (queue->len != 0)
		ft_dlstdel(&(queue->top), NULL);
	queue->bottom = NULL;
	queue->len = 0;
}

void			*qi_push(t_queue *queue, int value)
{
	t_dlist		*temp;

	temp = ft_dlstnew(&value, sizeof(value));
	if (temp == NULL)
		return (NULL);
	if (queue->top == NULL)
	{
		queue->len = 1;
		queue->top = temp;
		queue->bottom = temp;
	}
	else
	{
		ft_dlstadd(&(queue->top), temp);
		queue->top = temp;
		queue->len += 1;
	}
	return (queue);
}
