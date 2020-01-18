/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:00:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:37:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include "ft_timer.h"

void			load_and_prepare_lemin(t_lemin *lemin, int argc, char **argv)
{
	open_file_load_data(lemin, argc, argv);

	print_spend(0, "#time of load anthill");
	start_timer(4);
	check_data(lemin);
	prepare_data(lemin);	
	end_timer_print_spend(4, "#set lemin");
}

void			open_file_load_data(t_lemin *lemin, int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		load_data(lemin, 0);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		load_data(lemin, fd);
		close(fd);
	}
	else
		finish_prog(lemin, -1, -1, NULL);
	if (errno)
		finish_prog(lemin, -1, -1, NULL);
}
