#include "mlx.h"
#include "config.h"
#include "fdf.h"
void		draw_box(t_param *param, t_dot *dot1, t_dot *dot4, int color)
{
	t_dot		dot2;
	t_dot		dot3;


	dot2.x = dot4->x;
	dot2.color = 0xFF0000;
	dot2.y = dot1->y;
	dot3.x = dot1->x;
	dot3.color = 0xFF0000;
	dot3.y = dot4->y;
	draw_line_p(param, dot1, &dot2);
	draw_line_p(param, dot1, &dot3);
	draw_line_p(param, dot4, &dot2);
	draw_line_p(param, dot4, &dot3);
}

void		draw_menu(t_param *param, int color)
{
	void		*img_ptr;
	int		x;
	int		y;

	x = WINDOW_H_M;
	y = 15;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Zoom(+-): Mouse wheel");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Shift(Up, Right, Down, Left): WASD/Arrows");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"RotateOxOyOz(+-): QW/AS/ZX");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Projection(iso/paral/restart): I/P");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Oz(+-rev): 1/2/3");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Transparancy: T");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Color change: C");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"EXIT: esc");
	img_ptr = mlx_xpm_file_to_image(param->mlx_ptr, "menu.xpm", &x, &y);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, img_ptr, 0, 0); // destroy and yatayatayta
	mlx_destroy_image(param->mlx_ptr, img_ptr);
}
