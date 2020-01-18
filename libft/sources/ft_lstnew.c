/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:46:40 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr_list;

	if (!(ptr_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ptr_list->next = NULL;
	if (content)
	{
		if (!(ptr_list->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr_list->content, content, content_size);
		ptr_list->content_size = content_size;
	}
	else
	{
		ptr_list->content = NULL;
		ptr_list->content_size = 0;
	}
	return (ptr_list);
}
