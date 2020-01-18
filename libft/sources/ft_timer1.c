/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:48:44 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 19:48:55 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_timer.h"
#include "time.h"
#include "stdio.h"

void		reset_all_timers(void)
{
	size_t	i;

	i = 0;
	while (i < NUMBER_TIMERS)
	{
		set_t_spend(i, 0.0);
		set_t_start(i, 0);
		i++;
	}
}

void		reset_timer(int number_of_timer)
{
	set_t_spend(number_of_timer, 0.0);
	set_t_start(number_of_timer, 0);
}

void		start_timer(int number_of_timer)
{
	set_t_start(number_of_timer, clock());
}

double		end_timer(int number_of_timer)
{
	clock_t		end;
	double		spend_old;
	double		spend_new;

	end = clock();
	spend_old = get_t_spend(number_of_timer);
	spend_new = (double)(end - get_t_start(number_of_timer)) /
				(double)(CLOCKS_PER_SEC);
	set_t_spend(number_of_timer, spend_old + spend_new);
	return (spend_new);
}

double		end_timer_print_spend(int number_of_timer, char *str)
{
	double		spend_temp;

	spend_temp = end_timer(number_of_timer);
	ft_printf("%w%s %lf\n", 2, str, get_t_spend(number_of_timer));
	return (spend_temp);
}

void		print_spend(int number_of_timer, char *str)
{
	ft_printf("%w%s %lf\n", 2, str, get_t_spend(number_of_timer));
}
