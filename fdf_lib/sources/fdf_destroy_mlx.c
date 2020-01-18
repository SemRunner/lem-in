#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void	tmlx_destroy(t_mlx *m, int value_exit)
{
	if (m->main_im != NULL)
		mlx_destroy_image(m->ptr, m->main_im);
	if (m->win != NULL)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr != NULL)
		ft_memdel((void**)&(m->ptr));
	if (m->map != NULL)
		ft_memdel((void**)&(m->map));
	if (m->map_points != NULL)
		ft_memdel((void**)&(m->map_points));
	errno = 200;
	if (value_exit != -10)
		exit(value_exit);
}
