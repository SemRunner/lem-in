/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:49:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 20:12:35 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_quick(void **array, int first, int last, int (*cmp)())
{
	int		left;
	int		right;
	void	*middle;
	void	*tmp;

	if (first < last)
	{
		left = first;
		right = last;
		middle = array[(left + right) / 2];
		while (left <= right)
		{
			while (cmp(array[left], middle) < 0)
				left++;
			while (cmp(array[right], middle) > 0)
				right--;
			if (left <= right)
			{
				tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		}
		ft_sort_quick(array, first, right, cmp);
		ft_sort_quick(array, left, last, cmp);
	}
}
