#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void			put_main_image_to_window(t_mlx *m)
{
	mlx_put_image_to_window(m->ptr, m->win, m->main_im, 0, 0);
}