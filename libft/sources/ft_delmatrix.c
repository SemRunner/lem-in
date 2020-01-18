/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:32:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 16:32:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_delmatrix(void ***matrix, int num_of_lines)
{
	int		i;

	if (matrix == NULL || *matrix == NULL)
		return ;
	i = 0;
	while (i < num_of_lines)
	{
		ft_memdel((void**)&((*matrix)[i]));
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}
