/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:21:35 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:21:36 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen(int a)
{
	char	*s;
	int		tmp;

	s = ft_itoa(a);
	tmp = ft_strlen(s);
	ft_memdel((void**)&s);
	return (tmp);
}
