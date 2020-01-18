/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_legend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:47:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 18:23:07 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static void		strcatnbr(char *str, int nbr)
{
	char *tmp_str;

	tmp_str = ft_itoa(nbr);
	ft_strcat(str, tmp_str);
	ft_memdel((void**)&tmp_str);
}

static void		curr_angles_legend(t_mlx *m, int color)
{
	char	str[100];

	str[0] = '\0';
	ft_strcat(str, "x_angle = ");
	strcatnbr(str, m->x_angle);
	mlx_string_put(m->ptr, m->win, 10, 410, color, str);
	str[0] = '\0';
	ft_strcat(str, "y_angle = ");
	strcatnbr(str, m->y_angle);
	mlx_string_put(m->ptr, m->win, 10, 430, color, str);
	str[0] = '\0';
	ft_strcat(str, "z_angle = ");
	strcatnbr(str, m->z_angle);
	mlx_string_put(m->ptr, m->win, 10, 450, color, str);
}

static void		curr_cond_legend(t_mlx *m, int color)
{
	mlx_string_put(m->ptr, m->win, 10, 350, 0xFFFFFF, "CURRENT CONDITIONS:");
	if (m->projection_type == 0)
		mlx_string_put(m->ptr, m->win, 10, 370, color, "projection: ISO");
	else if (m->projection_type == 1)
		mlx_string_put(m->ptr, m->win, 10, 370, color, "projection: z");
	else if (m->projection_type == 2)
		mlx_string_put(m->ptr, m->win, 10, 370, color, "projection: x");
	else if (m->projection_type == 3)
		mlx_string_put(m->ptr, m->win, 10, 370, color, "projection: y");
	if (m->angle_projection_type == 0)
		mlx_string_put(m->ptr, m->win, 10, 390, color, "angle proj = 26.57");
	else if (m->angle_projection_type == 1)
		mlx_string_put(m->ptr, m->win, 10, 390, color, "angle proj = 30.00");
	else if (m->angle_projection_type == 2)
		mlx_string_put(m->ptr, m->win, 10, 390, color, "angle proj = 45.00");
}

void			put_fdf_legend(t_mlx *m)
{
	int color;

	color = 0x5f9e90;
	curr_cond_legend(m, 0x9f9e90);
	curr_angles_legend(m, 0x9f9e90);
	mlx_string_put(m->ptr, m->win, 10, 10, 0xFFFFFF,
			"KEY BINDINGS:");
	mlx_string_put(m->ptr, m->win, 10, 30, color, "+-zoom      : up,  down");
	mlx_string_put(m->ptr, m->win, 10, 50, color, "z_rotation  : left, right");
	mlx_string_put(m->ptr, m->win, 10, 70, color, "x_rotation  : w, s");
	mlx_string_put(m->ptr, m->win, 10, 90, color, "y_rotation  : a, d");
	mlx_string_put(m->ptr, m->win, 10, 110, color, "cam move    : u, j, h, k");
	mlx_string_put(m->ptr, m->win, 10, 130, color, "+-height    : r, f");
	mlx_string_put(m->ptr, m->win, 10, 150, color, "reset map   : x");
	mlx_string_put(m->ptr, m->win, 10, 170, color, "color       : z");
	mlx_string_put(m->ptr, m->win, 10, 190, color, "exit        : q, esc");
	mlx_string_put(m->ptr, m->win, 10, 220, color, "type projection:");
	mlx_string_put(m->ptr, m->win, 10, 240, color, "ISO (ang: 6): 1");
	mlx_string_put(m->ptr, m->win, 10, 260, color, "parallel z  : 2");
	mlx_string_put(m->ptr, m->win, 10, 280, color, "parallel x  : 3");
	mlx_string_put(m->ptr, m->win, 10, 300, color, "parallel y  : 4");
	mlx_string_put(m->ptr, m->win, 10, 320, color, "perspective : 5");
}
