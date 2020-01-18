/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:40:59 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len_str(int n, long long tmp_n)
{
	size_t len_str;

	len_str = n < 0 ? 1 : 0;
	if (tmp_n == 0)
		len_str += 1;
	else
		while (tmp_n > 0)
		{
			len_str += 1;
			tmp_n /= 10;
		}
	return (len_str);
}

char			*ft_itoa(int n)
{
	size_t		len_str;
	long long	tmp_n;
	char		*str_res;

	tmp_n = n < 0 ? -((long long)n) : n;
	len_str = count_len_str(n, tmp_n);
	if (!(str_res = (char*)malloc(sizeof(char) * (len_str + 1))))
		return (NULL);
	str_res[len_str--] = '\0';
	if (n < 0)
		str_res[0] = '-';
	else if (n == 0)
		str_res[0] = '0';
	while (tmp_n > 0)
	{
		str_res[len_str--] = (char)(tmp_n % 10 + 48);
		tmp_n /= 10;
	}
	return (str_res);
}
