/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictclearzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:22:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cycledict(t_dict **curr, t_dict **prev)
{
	if ((*curr)->content == NULL)
	{
		(*prev)->next = (*curr)->next;
		ft_memdel((void**)curr);
		(*curr) = (*prev)->next;
		if (*curr != NULL)
			(*curr)->prev = *prev;
	}
	else
	{
		(*prev) = (*curr);
		(*curr) = (*curr)->next;
	}
}

void			ft_dictclearzero(t_dict **dict)
{
	t_dict *curr;
	t_dict *prev;

	if (dict == NULL)
		return ;
	while ((*dict) && (*dict)->content == NULL)
	{
		curr = *dict;
		(*dict) = (*dict)->next;
		if (*dict != NULL)
			(*dict)->prev = NULL;
		ft_memdel((void**)&curr);
	}
	if (*dict == NULL)
		return ;
	prev = *dict;
	curr = (*dict)->next;
	while (curr)
		ft_cycledict(&curr, &prev);
}
