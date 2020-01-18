/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:50:59 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 17:48:58 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include "ft_timer.h"

int				ft_ishex(char *str)
{
	int		i;
	int		len_str;
	
	len_str = ft_strlen(str);
	if (len_str < 3 || len_str > 18)
		return (0);
	if (str[0] != '0' || str[1] != 'x')
		return (0);
	i = 1;
	while (++i < len_str)
	{
		if ('0' <= str[i] && str[i] <= '9')
			continue ;
		else if ('A' <= str[i] && str[i] <= 'F')
			continue ;
		else if ('a' <= str[i] && str[i] <= 'f')
			continue ;
		else
			return (0);
	}
	return (1);
}

int				ft_atoihex(char *str)
{
	int		res;
	int		i;
	int		len_str;

	res = 0;
	len_str = ft_strlen(str);
	if (len_str < 2)
		return (0);
	i = 1;
	while (++i < len_str)
	{
		if ('0' <= str[i] && str[i] <= '9')
			res = res * 16 + (str[i] - '0');
		else if ('A' <= str[i] && str[i] <= 'F')
			res = res * 16 + (10 + str[i] - 'A');
		else if ('a' <= str[i] && str[i] <= 'f')
			res = res * 16 + (10 + str[i] - 'a');
		else
			return (0);
	}
	return (res);
}

void			set_color_of_room(t_room *room_temp, char *color)
{
	if (ft_strlen(color) < 2)
		errno = 200;
	// if (ft_isint(color) == 0)
	// 	errno = 200;
	else
		room_temp->color = ft_atoihex(color);
//	ft_printf("%wcolor: %s, room.color: %d\n",2,color, room_temp.color);
}

t_room			set_room_property(char **strings, int next_flag)
{
	t_room			room_temp;

	room_temp.name = ft_strdup(strings[0]);
	if (ft_isint(strings[1]) == 0 || ft_isint(strings[2]) == 0)
		errno = 200;
	room_temp.x = ft_atoi(strings[1]);
	room_temp.y = ft_atoi(strings[2]);
	if (strings[3] != NULL)
	{
		room_temp.z = ft_atoi(strings[3]);
		if (strings[4] != NULL)
			set_color_of_room(&room_temp, strings[4]);
		else
			room_temp.color = NO_DEFINE;
	}
	else
	{
		room_temp.z = NO_DEFINE;
		room_temp.color = NO_DEFINE;
	}
	room_temp.start_end_flag = next_flag;
	room_temp.flow = 0;
	return (room_temp);
}

int				find_duplicates_rooms(t_dlist *list_rooms, t_room room_temp)
{
	t_dlist	*curr;
	t_room	*room;

	curr = list_rooms;
	while (curr != NULL)
	{
		room = curr->content;
		if (ft_strequ(room->name, room_temp.name))
			return (1);
		curr = curr->next;
	}
	return (0);
}

static int		set_first_end_room(t_lemin *lemin, int *next_flag)
{
	if (*next_flag == 1)
	{
		if (lemin->start_room == -1)
			lemin->start_room = lemin->count_rooms;
		else
			return (-1);
	}
	if (*next_flag == 2)
	{
		if (lemin->end_room == -1)
			lemin->end_room = lemin->count_rooms;
		else
			return (-1);
	}
	return (1);
}

int				load_ordered_room(t_dlist **lrooms, t_room *room)
{
	t_dlist		*curr;
	t_room		*room_curr;
	int			cmp;

	if (*lrooms == NULL)
		return (ft_dlst_addcontent_back(lrooms, room, sizeof(*room)) != NULL);
	curr = *lrooms;
	while (curr != NULL)
	{
		room_curr = curr->content;
		cmp = ft_strcmp(room_curr->name, room->name);
		if (cmp == 0)
			return (0);
		else if (cmp > 0)
		{
			if (curr == *lrooms)
				ft_dlst_addcontent(lrooms, room, sizeof(*room));
			else
				ft_dlst_addcontent(&curr, room, sizeof(*room));
			return (1);
		}
		curr = curr->next;
	}
	ft_dlst_addcontent_back(lrooms, room, sizeof(*room));
	return (1);
}

int				load_room_in_back(t_dlist **lrooms, t_room *room)
{
	return (ft_dlst_addcontent_back(lrooms, room, sizeof(*room)) != NULL);
}

void			load_room(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	char		**strings;
	t_room		room_temp;

	strings = NULL;
	if (!(strings = ft_strsplit(*line, ' ')) || strings[0] == NULL ||
		strings[1] == NULL || strings[2] == NULL)
	{
		ft_del_strsplit(&strings);
		finish_prog(lemin, -1, fd, line);
	}
	ft_memdel((void**)line);
	room_temp = set_room_property(strings, *next_flag);
	if (room_temp.color != NO_DEFINE)
		lemin->is_room_color = 1;
	ft_del_strsplit(&strings);
	if (set_first_end_room(lemin, next_flag) == -1)
		finish_prog(lemin, -1, fd, &(room_temp.name));
	if (load_room_in_back(&(lemin->list_rooms), &room_temp) == 0 ||
		ft_strstr(room_temp.name, "-"))
		finish_prog(lemin, -1, fd, &(room_temp.name));
	lemin->count_rooms++;
	*next_flag = 0;
}
