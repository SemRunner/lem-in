/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:17:21 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:17:40 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_max_len_int(int **matrix, int num_of_lines,
								int num_of_cols)
{
	int		i;
	int		j;
	int		len_tmp;
	int		max_len;

	max_len = 0;
	i = 0;
	while (i < num_of_lines)
	{
		j = 0;
		while (j < num_of_cols)
		{
			len_tmp = ft_intlen(matrix[i][j]);
			max_len = max_len > len_tmp ? max_len : len_tmp;
			j++;
		}
		i++;
	}
	return (max_len);
}

void			ft_print_intmatrix(int **matrix, int num_of_lines,
									int num_of_cols)
{
	int		i;
	int		j;
	int		max_len;

	max_len = find_max_len_int(matrix, num_of_lines, num_of_cols);
	i = 0;
	while (i < num_of_lines)
	{
		j = 0;
		while (j < num_of_cols)
		{
			ft_printf("%*d", max_len + 2, matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
