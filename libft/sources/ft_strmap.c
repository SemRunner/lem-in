/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:29:11 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp_str;
	size_t	len_s;

	if (!(s && f))
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (str == NULL)
		return (NULL);
	tmp_str = str;
	str[len_s] = '\0';
	while (*s)
		*(str++) = f(*(s++));
	return (tmp_str);
}
