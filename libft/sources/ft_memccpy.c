/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:23:39 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;

	if (n == 0 || (!dst && !src))
		return (NULL);
	dst_chr = (unsigned char *)dst;
	src_chr = (unsigned char *)src;
	while (n--)
	{
		if (*src_chr == (unsigned char)c)
		{
			*dst_chr = *src_chr;
			return (void *)(++dst_chr);
		}
		else
			*(dst_chr++) = *(src_chr++);
	}
	return (NULL);
}
