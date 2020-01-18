/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:39:17 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 20:39:23 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			vector_int_assign(int *vector, int len, int value)
{
	int i;

	i = 0;
	while (i < len)
	{
		vector[i] = value;
		i++;
	}
}

void			vector_int_print(int *vector, int len, int fd)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%w%d ", fd, vector[i]);
		i++;
	}
	ft_printf("%w\n", fd);
}
