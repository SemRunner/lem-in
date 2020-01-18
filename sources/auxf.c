/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:33:22 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:38:46 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void			print_newgraph(t_lemin *l)
{
	int			i;
	t_dlist		*curr;
	t_gedge		*edg;

	i = -1;
	while (++i < l->size_matrix)
	{
		ft_printf("vert %d: ", i);
		curr = l->g[i];
		while (curr != NULL)
		{
			edg = curr->content;
			ft_printf("%d ", edg->to);
			curr = curr->next;
		}
		ft_printf("\n");
	}
}
