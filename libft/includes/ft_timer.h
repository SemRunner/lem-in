/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:50:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 19:50:59 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIMER_H
# define FT_TIMER_H

# include "time.h"

# define		NUMBER_TIMERS 30

void		set_t_start(int number_of_timer, clock_t value);
clock_t		get_t_start(int number_of_timer);
void		set_t_spend(int number_of_timer, double value);
double		get_t_spend(int number_of_timer);

void		reset_all_timers(void);
void		reset_timer(int number_of_timer);
void		start_timer(int number_of_timer);
double		end_timer(int number_of_timer);
double		end_timer_print_spend(int number_of_timer, char *str);
void		print_spend(int number_of_timer, char *str);

#endif
