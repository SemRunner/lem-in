#include "fdf.h"
#include "libft.h"

void				putcircle(t_mlx *m, t_point center, int radius,
							int not_black)
{
	int		x;
	int		y;
	int		delta;
	int		error;
	int		color;

	color = not_black == 0 ? 0 : center.color;
	x = 0;
	y = radius;
	delta = 1 - 2 * radius;
	error = 0;
	while (y >= 0)
	{
		putpixel(m, center.x + x, center.y + y, color);
		putpixel(m, center.x + x, center.y - y, color);
		putpixel(m, center.x - x, center.y + y, color);
		putpixel(m, center.x - x, center.y - y, color);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
			delta += 2 * (++x) + 1;
		else if ((delta > 0) && error > 0)
			delta -= 2 * (--y) + 1;
		else
			delta += 2 * ((++x) - (y--));
	}
}

void				putcircle_thick(t_mlx *m, t_point center,
								int radius, int not_black)
{
	putcircle(m, center, radius, not_black);
	putcircle(m, center, radius - 1, not_black);
	putcircle(m, center, radius + 1, not_black);
}

void				putcircle_full_thick(t_mlx *m, t_point center,
								int radius, int not_black)
{
	putcircle(m, center, radius, not_black);
	putcircle(m, center, radius - 1, not_black);
	putcircle(m, center, --radius, not_black);
	while (radius)
		putcircle(m, center, --radius, not_black);
}