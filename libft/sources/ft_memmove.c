/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:56:38 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;

	if (len == 0 || (!dst && !src))
		return (dst);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		dst_chr = (unsigned char *)dst;
		src_chr = (unsigned char *)src;
		while (len--)
			dst_chr[len] = src_chr[len];
	}
	return (dst);
}
