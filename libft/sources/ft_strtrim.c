/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:50:27 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*empty_s(void)
{
	char	*ptr_res;

	if (!(ptr_res = (char *)malloc(sizeof(char))))
		return (NULL);
	*ptr_res = '\0';
	return (ptr_res);
}

char			*ft_strtrim(char const *s)
{
	size_t	end_s;
	char	*ptr_res;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (empty_s());
	end_s = ft_strlen(s) - 1;
	while (s[end_s] == ' ' || s[end_s] == '\n' || s[end_s] == '\t')
		end_s--;
	if (!(ptr_res = (char *)malloc(sizeof(char) * (++end_s + 1))))
		return (NULL);
	ptr_res[end_s] = '\0';
	ptr_res = ft_strncpy(ptr_res, s, end_s);
	return (ptr_res);
}
