/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 17:26:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "ft_timer.h"

void			load_link(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	char			**strings;
	t_room_ways		room_ways_temp;
	strings = NULL;
	if (!(strings = ft_strsplit(*line, '-')))
		finish_prog(lemin, -1, fd, line);
	if (strings[0] == NULL || strings[1] == NULL)
	{
		ft_del_strsplit(&strings);
		finish_prog(lemin, -1, fd, line);
	}
	room_ways_temp.start_room = ft_strdup(strings[0]);
	room_ways_temp.end_room = ft_strdup(strings[1]);
	ft_del_strsplit(&strings);
	ft_dlst_addcontent_back(&(lemin->room_ways), &room_ways_temp,
							sizeof(t_room_ways));
	if (room_ways_temp.start_room == NULL || room_ways_temp.end_room == NULL)
		finish_prog(lemin, -1, fd, line);
	lemin->count_edges++;
	*next_flag = 0;
}

static void		load_line(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	if (ft_strequ(*line, "##start") && *next_flag == 0)
		*next_flag = 1;
	else if (ft_strequ(*line, "##end") && *next_flag == 0)
		*next_flag = 2;
	else if (ft_strnstr(*line, "#", 1) && *next_flag == 0)
		*next_flag = 0;
	else if (ft_strstr(*line, " "))
		load_room(lemin, line, next_flag, fd);
	else if (ft_strstr(*line, "-"))
		load_link(lemin, line, next_flag, fd);
	else if (!(lemin->is_visu))
		errno = -1;
	ft_memdel((void**)line);
	if (errno)
		finish_prog(lemin, -1, fd, NULL);
}

int				load_position_ant(t_lemin *lemin, char *line, int step)
{
	char		**strings;
	t_ant_move	am;
	int			num_ant;

	if (!(strings = ft_strsplit(line + 1, '-')))
		return (0);
	if (strings[0] == NULL || strings[1] == NULL)
	{
		ft_del_strsplit(&strings);
		return (0);
	}
	else
	{
		num_ant = ft_atoi(strings[0]);
		am.step = step;
		am.to_name = ft_strdup(strings[1]);
		am.to = -1;
		ft_dlst_addcontent_back(&(lemin->ants_moving[num_ant - 1]), &am,
							sizeof(am));
	}
	ft_del_strsplit(&strings);
	return (1);
}

void			load_line_moving_ants(t_lemin *lemin, char **line,
									int fd, int step)
{
	char		**strings;
	int			i;

	strings = NULL;
	if (!(strings = ft_strsplit(*line, ' ')))
		finish_prog(lemin, -1, fd, NULL);
	lemin->max_step++;
	i = 0;
	while (strings[i] != NULL)
	{
		if (load_position_ant(lemin, strings[i], step) == 0)
		{
			ft_del_strsplit(&strings);
			finish_prog(lemin, -1, fd, NULL);
		}
		i++;
	}
	ft_del_strsplit(&strings);
}

int				get_next_line_temp(int fd, char **line)
{
	int res;

	start_timer(9);
	res = get_next_line(fd, line);
	end_timer(9);
	return (res);
}

void			load_data(t_lemin *lemin, int fd)
{
	int				res;
	char			*line;
	int				next_flag;
	int				step;

	start_timer(0);
	line = NULL;
	next_flag = 0;
	step = 0;
	if (fd < 0)
		finish_prog(lemin, -1, fd, NULL);
	load_number_of_ants(lemin, fd);
	while ((res = get_next_line_temp(fd, &line)) == 1)
	{
		start_timer(8);
		if (lemin->is_visu == 1 && line[0] == 'L')
			load_line_moving_ants(lemin, &line, fd, ++step);
		else
			load_line(lemin, &line, &next_flag, fd);
		ft_memdel((void**)&line);
		end_timer(8);
	}
	ft_memdel((void**)&line);
	if (res == -1)
		finish_prog(lemin, -1, fd, NULL);
	if (lemin->count_rooms == 0 || lemin->count_edges == 0)
		finish_prog(lemin, -1, fd, NULL);
	lemin->size_matrix = lemin->count_rooms * 2;
	end_timer(0);
}
