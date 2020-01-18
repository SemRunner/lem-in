#include "libft.h"
#include "fdf.h"

static void	init_dxy_xy(t_point *dxy, t_point *xy, t_point start,
							t_point end)
{
	dxy->x = end.x - start.x;
	dxy->y = end.y - start.y;
	xy->x = start.x;
	xy->y = start.y;
}

static void	putline_low(t_mlx *m, t_point start, t_point end, int not_black)
{
	t_point	dxy;
	t_point	xy;
	int		yi;
	int		d;

	init_dxy_xy(&dxy, &xy, start, end);
	yi = 1;
	if (dxy.y < 0)
	{
		yi = -1;
		dxy.y = -dxy.y;
	}
	d = 2 * dxy.y - dxy.x;
	while (xy.x <= end.x)
	{
		(not_black == 0x0) ? putpixel(m, xy.x, xy.y, not_black) : putpixel(m,
			xy.x, xy.y, calc_color_gradient(start, end, calc_perc(start.x, end.x, xy.x)));
		if (d > 0)
		{
			xy.y = xy.y + yi;
			d = d - 2 * dxy.x;
		}
		d = d + 2 * dxy.y;
		xy.x++;
	}
}

static void	putline_high(t_mlx *m, t_point start, t_point end, int not_black)
{
	t_point	dxy;
	t_point	xy;
	int		xi;
	int		d;

	init_dxy_xy(&dxy, &xy, start, end);
	xi = 1;
	if (dxy.x < 0)
	{
		xi = -1;
		dxy.x = -dxy.x;
	}
	d = 2 * dxy.x - dxy.y;
	while (xy.y <= end.y)
	{
		(not_black == 0x0) ? putpixel(m, xy.x, xy.y, not_black) : putpixel(m,
			xy.x, xy.y, calc_color_gradient(start, end, calc_perc(start.y, end.y, xy.y)));
		if (d > 0)
		{
			xy.x = xy.x + xi;
			d = d - 2 * dxy.y;
		}
		d = d + 2 * dxy.x;
		xy.y++;
	}
}

void		putline(t_mlx *m, t_point start, t_point end, int not_black)
{
	if (ABS(end.y - start.y) < ABS(end.x - start.x))
	{
		if (start.x > end.x)
			putline_low(m, end, start, not_black);
		else
			putline_low(m, start, end, not_black);
	}
	else
	{
		if (start.y > end.y)
			putline_high(m, end, start, not_black);
		else
			putline_high(m, start, end, not_black);
	}
}

void				putline_thick(t_mlx *m, t_point start,
								t_point end, int not_black)
{
	int		diffx;
	int		diffy;

	putline(m, start, end, not_black);
	diffx = ABS(start.x - end.x);
	diffy = ABS(start.y - end.y);
	if (diffx < diffy)
	{
		start.x -= 1;
		end.x -= 1;
		putline(m, start, end, not_black);
		start.x += 2;
		end.x += 2;
		putline(m, start, end, not_black);
	}
	else
	{
		start.y -= 1;
		end.y -= 1;
		putline(m, start, end, not_black);
		start.y += 2;
		end.y += 2;
		putline(m, start, end, not_black);
	}
}