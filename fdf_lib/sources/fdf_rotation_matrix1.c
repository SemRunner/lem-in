/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation_matrix1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:53:55 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void			mult_rmatrix(double *res, double *a, double *b)
{
	int		i;
	int		j;
	int		k;
	double	tmp[16];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tmp[i * 4 + j] = 0;
			k = -1;
			while (++k < 4)
				tmp[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
		}
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res[i * 4 + j] = tmp[i * 4 + j];
	}
}
