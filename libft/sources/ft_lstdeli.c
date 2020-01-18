/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:15:41 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeli(t_list **alst, size_t nbr, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	*curr;
	t_list	*prev;

	if (!(*alst))
		return ;
	if (nbr == 0)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	prev = *alst;
	curr = prev->next;
	i = 1;
	while (curr && i < nbr)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (!(curr))
		return ;
	prev->next = curr->next;
	del(curr->content, (curr)->content_size);
	ft_memdel((void**)(&curr));
}
