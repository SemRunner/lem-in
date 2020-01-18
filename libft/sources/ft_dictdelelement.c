/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictdelelement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:27:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dictdelelement(t_dict **dict, t_dict **element,
							void (*del)(void *, size_t))
{
	t_dict *curr;

	if (dict == NULL || *dict == NULL)
		return ;
	if (element == NULL || *element == NULL)
		return ;
	curr = *element;
	if (curr->prev != NULL)
		(curr->prev)->next = curr->next;
	if (curr->next != NULL)
		(curr->next)->prev = curr->prev;
	if (del != NULL)
		del(curr->content, curr->content_size);
	if ((*dict) == (*element))
		(*dict) = (*element)->next;
	ft_memdel((void **)element);
}
