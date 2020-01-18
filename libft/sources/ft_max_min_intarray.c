/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min_intarray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:18:31 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:18:32 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_max_intarray(int *arr, int size)
{
	int		i;
	int		res;

	if (size <= 0)
		return (NO_DEFINE);
	res = arr[0];
	i = 0;
	while (++i < size)
		if (arr[i] > res)
			res = arr[i];
	return (res);
}

int			ft_min_intarray(int *arr, int size)
{
	int		i;
	int		res;

	if (size <= 0)
		return (NO_DEFINE);
	res = arr[0];
	i = 0;
	while (++i < size)
		if (arr[i] < res)
			res = arr[i];
	return (res);
}
