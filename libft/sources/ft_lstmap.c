/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:45:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *curr_el;
	t_list *new_el;

	new_lst = NULL;
	if (lst && f)
	{
		new_lst = f(lst);
		curr_el = new_lst;
		lst = lst->next;
		while (lst)
		{
			new_el = f(lst);
			curr_el->next = new_el;
			curr_el = curr_el->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
