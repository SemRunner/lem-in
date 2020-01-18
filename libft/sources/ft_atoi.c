/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:23:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 18:50:46 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	check_start(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] == '\r') || (str[i] == '\v') || (str[i] == '\n')
			|| (str[i] == '\t') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int			neg;
	long long	val;
	size_t		num_char;

	neg = 0;
	val = 0;
	num_char = check_start(str);
	if (str[num_char] == '-')
	{
		neg = 1;
		num_char++;
	}
	else if (str[num_char] == '+')
	{
		num_char++;
	}
	while ((str[num_char] >= '0') && (str[num_char] <= '9'))
	{
		val = (val * 10) - (str[num_char] - '0');
		num_char++;
	}
	return (neg == 1 ? val : -val);
}
