#include "libft.h"
#include "fdf.h"

void		putpixel(t_mlx *m, int x, int y, int color)
{
	if ((0 <= x && x < m->width) && (0 <= y && y < m->height))
		m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
}