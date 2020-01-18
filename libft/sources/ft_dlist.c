/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:49:51 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*return_null(void)
{
	errno = ENOMEM;
	return (NULL);
}

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*ptr_list;

	if (!(ptr_list = (t_dlist*)malloc(sizeof(t_dlist))))
		return (return_null());
	ptr_list->next = NULL;
	ptr_list->prev = NULL;
	if (content)
	{
		if (!(ptr_list->content = (void*)malloc(content_size)))
			return (return_null());
		ft_memcpy(ptr_list->content, content, content_size);
		ptr_list->content_size = content_size;
	}
	else
	{
		ptr_list->content = NULL;
		ptr_list->content_size = 0;
	}
	ptr_list->prev = ptr_list;
	return (ptr_list);
}

void		ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	t_dlist *prev;

	if (!(alst))
		return ;
	if (new)
	{
		new->next = *alst;
		if (*alst)
		{
			prev = (*alst)->prev;
			new->prev = (*alst)->prev;
			(*alst)->prev = new;
			if (prev->next == (*alst))
				prev->next = new;
		}
		*alst = new;
	}
}

void		ft_dlst_addback(t_dlist **alst, t_dlist *new)
{
	t_dlist		*temp;

	if (alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->prev = *alst;
	}
	else
	{
		temp = (*alst)->prev;
		temp->next = new;
		new->prev = temp;
		(*alst)->prev = new;
	}
}

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*next;
	t_dlist	*curr;

	curr = *alst;
	while (curr)
	{
		next = curr->next;
		if (*del != NULL)
			del(curr->content, curr->content_size);
		if (curr->content_size != 0)
			ft_memdel((void**)&(curr->content));
		ft_memdel((void**)&curr);
		curr = next;
	}
	*alst = NULL;
}
