/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:47:17 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 19:47:18 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr_new;

	if (ptr == NULL)
	{
		return ((void*)malloc(size));
	}
	if (size == 0)
	{
		ft_memdel((void**)&ptr);
		return ((void*)ft_memalloc(1));
	}
	if (!(ptr_new = (void*)malloc(size)))
	{
		errno = ENOMEM;
		ft_memdel((void**)&ptr);
		return (NULL);
	}
	ft_memcpy(ptr_new, ptr, size);
	ft_memdel((void**)&ptr);
	return (ptr_new);
}
