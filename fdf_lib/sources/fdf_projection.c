#include "fdf.h"
#include "libft.h"

void				projection_points(t_mlx *m)
{
	t_point		res;
	int			i;

	i = -1;
	while (++i < m->quantity_points)
	{
		res = get_proj_point_to_draw(m, i);
		res.x += m->camera_x;
		res.y += m->camera_y;
		m->map_points[i].x = res.x;
		m->map_points[i].y = res.y;
		m->map_points[i].z = res.z;
	}
}
