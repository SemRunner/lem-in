/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:14:44 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dictadd(t_dict **adict, t_dict *new)
{
	t_dict *next;

	if (*adict == NULL)
	{
		*adict = new;
		return ;
	}
	if (new)
	{
		if ((*adict)->next == NULL)
		{
			(*adict)->next = new;
			new->prev = (*adict);
		}
		else
		{
			next = (*adict)->next;
			(*adict)->next = new;
			new->prev = (*adict);
			new->next = next;
			next->prev = new;
		}
	}
}
