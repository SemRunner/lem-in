/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:19:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/16 19:26:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# define FDF_KEY_UP 126
# define FDF_KEY_DOWN 125
# define FDF_KEY_ESC 53
# define FDF_KEY_PLUS 24
# define FDF_KEY_MINUS 27
# define FDF_KEY_NP_PLUS 69
# define FDF_KEY_NP_MINUS 78
# define FDF_SCROLL_U 4
# define FDF_SCROLL_D 5
# define FDF_KEY_1 18
# define FDF_KEY_2 19
# define FDF_KEY_3 20
# define FDF_KEY_4 21
# define FDF_KEY_5 23
# define FDF_KEY_6 22
# define FDF_KEY_7 26
# define FDF_KEY_A 0
# define FDF_KEY_C 8
# define FDF_KEY_Q 12
# define FDF_KEY_W 13
# define FDF_KEY_X 7
# define FDF_KEY_Z 6

# define FDF_MOUSE_LEFT 1
# define FDF_MOUSE_RIGHT 2

# define FDF_WHITE 0xFFFFFF
# define FDF_LGREEN 0x5F9E90
# define FDF_GRAY 0x9f9e90

# define FDF_ANGLE_ROTATE_PRECISION 15

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				x0;
	int				y0;
	int				z0;
}					t_point;

typedef struct		s_rot
{
	double			r_x[16];
	double			r_y[16];
	double			r_z[16];
	double			r_persp[16];
	double			r_all[16];
}					t_rot;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;

	int				width;
	int				height;
	int				bits_pixel;
	int				size_line;
	int				endian;
	int				*map;
	int				map_x;
	int				map_y;
	int				max_h;
	int				min_h;
	t_point			*map_points;
	int				quantity_points;
	int				zoom_coef;
	double			zoom;
	int				h_coef;
	double			h;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				rotate_prec;
	int				angle_projection_type;
	int				prev_ang_proj_type;
	int				projection_type;
	int				prev_proj_type;
	int				camera_x;
	int				camera_y;

	double			proj_per_k;

	int				type_color_spectrum;

	char			in_move;
	int				mouse_x;
	int				mouse_y;
	char			mleft_pressed;
	char			mright_pressed;

	t_rot			*mr;
}					t_mlx;

/*
** init and destroy data
** file initialize_mlx.c
*/

void				tmlx_destroy(t_mlx *m, int value_exit);
void				tmlx_initialize(t_mlx *m, int x, int y);
int					tmlx_create_mlx(t_mlx *m, char *title);
void				reset_map(t_mlx *m);

/*
** load data
** file readfile0.c readfile1.c readfile2.c
*/

void				first_check_file(t_mlx *m, char *filename);
void				load_map(t_mlx *m, char *filename);
int					check_file(t_mlx *m, int fd);
int					put_map(t_mlx *m, int fd);
void				set_base_coord(t_mlx *m);
void				calculate_max_min_h_in_map(t_mlx *m);

/*
** working functions
** files legend.c keyhook.c
*/

void				put_fdf_legend(t_mlx *m);
int					keyhooks(int keycode, t_mlx *m);
int					check_keyhooks_fdf(int k);
void				calc_hzoom(t_mlx *m, int coef);

int					fdf_in_frontiers(int x, int y, t_mlx *m);
int					fdf_mouse_move(int x, int y, t_mlx *m);
int					fdf_mouse_press(int key, int x, int y, t_mlx *m);
int					fdf_mouse_release(int key, int x, int y, t_mlx *m);

/*
** making map_points from map. it's doing on every iteration, in map_points
** putting base points, than that points changing
** file make_map_points.c
*/

void				make_map_points(t_mlx *m);
void				calc_parameter_maps(t_mlx *m);

void				draw_surface(t_mlx *m, int not_black);

/*
** rotation functions
** file rotation.c
*/

void				set_rotate_matrix_zero(double *m);
void				set_rotate_matrix_one(double *m);
void				calc_rotate_x(t_rot *mr, int x_angle);
void				calc_rotate_y(t_rot *mr, int y_angle);
void				calc_rotate_z(t_rot *mr, int z_angle);
void				mult_rmatrix(double *res, double *a, double *b);
void				mult_xyz_rmatrix(t_mlx *m, double *rmatrix, t_point *p);
void				mult_xyz_rmatrix_persp(t_mlx *m, double *rmatrix,
											t_point *p);

void				rotate_points(t_mlx *m);

/*
** projection functions
*/

t_point				get_point_to_draw(t_mlx *m, int i);
t_point				get_proj_point_to_draw(t_mlx *m, int i);
void				iso(t_mlx *m, int *x, int *y, int z);

void				projection_points(t_mlx *m);

/*
** draw pixel, line, figures
** file draw.c draw_point.c get_proj_point.c iso_transform.c
**      fdf_draw_figures.c
*/

void				put_main_image_to_window(t_mlx *m);
void				clear_image(t_mlx *m);

void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end,
							int not_black);
void				putline_thick(t_mlx *m, t_point start, t_point end,
							int not_black);
void				putbox(t_mlx *m, t_point center, int size, int not_black);
void				putbox_full(t_mlx *m, t_point center, int size,
								int not_black);
void				putcircle(t_mlx *m, t_point center, int radius,
							int not_black);
void				putcircle_thick(t_mlx *m, t_point center, int radius,
							int not_black);
void				putcircle_full_thick(t_mlx *m, t_point center,
								int radius, int not_black);

void				drawpoint(t_mlx *m, int i);

/*
** work with color
** file color.c
*/

double				calc_perc(int start, int end, int curr);
int					calc_gradient(int start, int end, double percent);
int					calc_color_gradient(t_point start, t_point end, double perc);
int					calc_color_spectrum(int type_color_spectrum, int percent);
void				set_mappoints_color(t_mlx *m);

#endif
