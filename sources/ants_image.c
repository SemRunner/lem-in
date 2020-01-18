#include "libft.h"
#include "lemin.h"
#include "fdf.h"
#include "mlx.h"
#include "lemin_mlx.h"

int			initialize_ants_image(t_lemin_mlx *lm)
{
	lm->ants_image = mlx_new_image(lm->m->ptr, lm->m->width, lm->m->height);
	lm->data_ants = (int*)mlx_get_data_addr(lm->ants_image,
		&(lm->m->bits_pixel), &(lm->size_line_data_ants), &(lm->m->endian));
	transparent_ants_image(lm);
	return (1);
}

void		transparent_ants_image(t_lemin_mlx *lm)
{
	int		i;

	i = -1;
	while (++i < lm->m->height * lm->m->width)
		lm->data_ants[i] = 0xFF000000;
}

void		put_ant_on_ants_image(t_lemin_mlx *lm, int x, int y)
{
	int		i;
	int		j;

	x -= lm->size_ant_im / 2;
	y -= lm->size_ant_im / 2;

	i = -1;
	while (++i < lm->size_ant_im)
	{
		j = -1;
		while (++j < lm->size_ant_im)
		{
			if (0 <= (x + j) && (x + j) < lm->m->width  && (0 <= (y + i) && (y + 1) < lm->m->height))
				if ((unsigned int)lm->data_ant_im[i * lm->size_line_ant_im / sizeof(int) + j] != 0xFF000000)
					lm->data_ants[(y + i) * lm->size_line_data_ants / sizeof(int) + x + j] =
						lm->data_ant_im[i * lm->size_line_ant_im / sizeof(int) + j];
		}
	}
}

void		put_ants_image_to_window(t_lemin_mlx *lm)
{
	mlx_put_image_to_window(lm->m->ptr, lm->m->win, lm->ants_image, 0, 0);
}