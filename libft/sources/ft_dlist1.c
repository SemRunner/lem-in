/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:47:27 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dlst_len(t_dlist *lst)
{
	int		i;
	t_dlist	*curr;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void		*ft_dlst_addcontent_back(t_dlist **list, void *content,
										size_t content_size)
{
	t_dlist		*temp;

	temp = ft_dlstnew(content, content_size);
	if (temp == NULL)
		return (NULL);
	ft_dlst_addback(list, temp);
	return (list);
}

void		*ft_dlst_addcontent(t_dlist **list, void *content,
										size_t content_size)
{
	t_dlist		*temp;

	temp = ft_dlstnew(content, content_size);
	if (temp == NULL)
		return (NULL);
	ft_dlstadd(list, temp);
	return (list);
}
