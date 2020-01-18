/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:53:09 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:21:03 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_del_strsplit(char ***strings)
{
	size_t	i;

	if (strings == NULL || *strings == NULL)
		return ;
	i = 0;
	while ((*strings)[i] != NULL)
	{
		ft_memdel((void**)&((*strings)[i]));
		i++;
	}
	free(*strings);
	*strings = NULL;
}
