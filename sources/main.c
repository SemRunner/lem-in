/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:35:12 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "float.h"
#include <stdio.h>
#include "ft_timer.h"

 // FIXME on zoom perspective projection freezing (may be zero about 0? need check)

int				main(int argc, char **argv)
{
	t_lemin		lemin;

	tlemin_initialize(&lemin);
	reset_all_timers();
	errno = 0;
	load_and_prepare_lemin(&lemin, argc, argv);
	errno = 0;
	start_timer(20);
	solve(&lemin);
	end_timer_print_spend(20, "#solve lemin");
	if (lemin.count_ways == 0 || errno != 0)
		finish_prog(&lemin, -1, -1, NULL);
	print_anthill(&lemin);
	going_ants(&lemin);
	finish_prog(&lemin, 0, -1, NULL);
}
