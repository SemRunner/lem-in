/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:30:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 22:30:03 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_oversize(char *str)
{
	int			neg;
	long long	val;
	size_t		num_char;

	neg = 0;
	val = 0;
	num_char = 0;
	if (str[num_char] == '-')
	{
		neg = 1;
		num_char++;
	}
	else if (str[num_char] == '+')
		num_char++;
	while ((str[num_char] >= '0') && (str[num_char] <= '9'))
	{
		val = (val * 10) + (str[num_char] - '0');
		if (val > 2147483647 || (neg == 1 && val > 2147483648))
			return (0);
		num_char++;
	}
	return (1);
}

int				ft_isint(char *str)
{
	int i;
	int count_numbers;

	if (str == NULL || str[0] == '\0')
		return (0);
	else if (ft_isdigit(str[0]))
		count_numbers = 1;
	else if (str[0] == '-' || str[0] == '+')
		count_numbers = 0;
	else
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		count_numbers++;
		i++;
	}
	if (count_numbers == 0)
		return (0);
	else
		return (check_oversize(str));
}
