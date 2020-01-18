/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictdelelement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:27:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dictdelbykey(t_dict **dict, int key, void (*del)(void *, size_t))
{
	t_dict *curr;

	if (dict == NULL || *dict == NULL)
		return ;
	curr = ft_dictgetvalue(*dict, key);
	if (curr != NULL)
		ft_dictdelelement(dict, &curr, del);
}
