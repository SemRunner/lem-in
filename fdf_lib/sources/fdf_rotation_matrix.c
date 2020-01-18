/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 15:39:02 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void			set_rotate_matrix_zero(double *m)
{
	int i;

	i = -1;
	while (++i < 16)
		m[i] = 0.0;
}

void			set_rotate_matrix_one(double *m)
{
	set_rotate_matrix_zero(m);
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
}

void			calc_rotate_x(t_rot *mr, int x_angle)
{
	double	angle;

	angle = x_angle * M_PI / 180;
	set_rotate_matrix_zero(mr->r_x);
	mr->r_x[0] = 1;
	mr->r_x[5] = cos(angle);
	mr->r_x[6] = sin(angle);
	mr->r_x[9] = -sin(angle);
	mr->r_x[10] = cos(angle);
	mr->r_x[15] = 1;
}

void			calc_rotate_y(t_rot *mr, int y_angle)
{
	double	angle;

	angle = y_angle * M_PI / 180;
	set_rotate_matrix_zero(mr->r_y);
	mr->r_y[0] = cos(angle);
	mr->r_y[2] = sin(angle);
	mr->r_y[5] = 1;
	mr->r_y[8] = -sin(angle);
	mr->r_y[10] = cos(angle);
	mr->r_y[15] = 1;
}

void			calc_rotate_z(t_rot *mr, int z_angle)
{
	double	angle;

	angle = z_angle * M_PI / 180;
	set_rotate_matrix_zero(mr->r_z);
	mr->r_z[0] = cos(angle);
	mr->r_z[1] = -sin(angle);
	mr->r_z[4] = sin(angle);
	mr->r_z[5] = cos(angle);
	mr->r_z[10] = 1;
	mr->r_z[15] = 1;
}
