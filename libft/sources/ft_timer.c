/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:46:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 20:13:25 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_timer.h"
#include "time.h"

clock_t		g_start[NUMBER_TIMERS];
double		g_spend[NUMBER_TIMERS];

void		set_t_start(int number_of_timer, clock_t value)
{
	g_start[number_of_timer] = value;
}

clock_t		get_t_start(int number_of_timer)
{
	return (g_start[number_of_timer]);
}

void		set_t_spend(int number_of_timer, double value)
{
	g_spend[number_of_timer] = value;
}

double		get_t_spend(int number_of_timer)
{
	return (g_spend[number_of_timer]);
}
