/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:54:58 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 12:19:36 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*clear_s1(char **s1)
{
	ft_memdel((void**)s1);
	return (NULL);
}

void			*ft_strnjoin(char **s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s2 || n == 0 || ft_strlen(s2) == 0)
		return (*s1);
	len_s1 = *s1 ? ft_strlen(*s1) : 0;
	len_s2 = ft_strlen(s2);
	n = len_s2 > n ? n : len_s2;
	if (len_s1 > __SIZE_MAX__ - len_s2)
		return (clear_s1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len_s1 + n + 1))))
		return (clear_s1);
	ft_memcpy(ptr, (void*)(*s1), len_s1);
	ptr += len_s1;
	ft_memcpy(ptr, (void*)s2, n);
	ptr[n] = '\0';
	ptr -= len_s1;
	if (*s1)
		ft_memdel((void**)s1);
	*s1 = ptr;
	return (ptr);
}
