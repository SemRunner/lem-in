/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 18:08:39 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		correct_angles(t_mlx *m)
{
	m->x_angle %= 360;
	m->y_angle %= 360;
	m->z_angle %= 360;
}

static void		calc_r_x_y_z(t_mlx *m, t_rot *mr)
{
	calc_rotate_x(mr, m->x_angle);
	calc_rotate_y(mr, m->y_angle);
	calc_rotate_z(mr, m->z_angle);
}

void			mult_xyz_rmatrix(t_mlx *m, double *rmatrix, t_point *p)
{
	t_point		prev;
	double		tmp;

	prev = *p;
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	p->x = prev.x * rmatrix[0] + prev.y * rmatrix[4] +
			prev.z * rmatrix[8] + 1 * rmatrix[12];
	p->y = prev.x * rmatrix[1] + prev.y * rmatrix[5] +
			prev.z * rmatrix[9] + 1 * rmatrix[13];
	p->z = prev.x * rmatrix[2] + prev.y * rmatrix[6] +
			prev.z * rmatrix[10] + 1 * rmatrix[14];
	tmp = prev.x * rmatrix[3] + prev.y * rmatrix[7] +
			prev.z * rmatrix[11] + 1 * rmatrix[15];
	p->x += m->width / 2;
	p->y += m->height / 2;
}

void			rotate_points(t_mlx *m)
{
	t_rot	mr;
	int		i;

	m->mr = &mr;
	correct_angles(m);
	calc_r_x_y_z(m, &mr);
	set_rotate_matrix_one(mr.r_all);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_z);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_y);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_x);
	i = -1;
	while (++i < m->quantity_points)
		mult_xyz_rmatrix(m, mr.r_all, &(m->map_points[i]));
}
