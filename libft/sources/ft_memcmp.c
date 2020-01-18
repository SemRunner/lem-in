/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:14:11 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_chr;
	unsigned char	*s2_chr;

	if (n == 0 || (!s1 && !s2))
		return (0);
	s1_chr = (unsigned char *)s1;
	s2_chr = (unsigned char *)s2;
	i = 0;
	while (s1_chr[i] == s2_chr[i] && i < n - 1)
		i++;
	return (s1_chr[i] - s2_chr[i]);
}
