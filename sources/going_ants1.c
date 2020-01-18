/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   going_ants1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:58:32 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 20:06:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int				count_bandwidth(int flow_len, int step)
{
	if (step - flow_len + 1 > 0)
		return (step - flow_len + 1);
	else
		return (0);
}
