/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:35:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lsti(t_list *alst, size_t nbr)
{
	size_t	i;

	if (!alst)
		return (NULL);
	i = 0;
	while (alst && i < nbr)
	{
		alst = alst->next;
		i++;
	}
	if (i == nbr)
		return (alst);
	else
		return (NULL);
}
