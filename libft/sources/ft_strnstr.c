/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:17:55 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;
	size_t	len_haystack;

	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (len < len_needle || len_haystack < len_needle)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i < len - len_needle + 1)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (char *)(haystack + i);
		i++;
	}
	return (NULL);
}
