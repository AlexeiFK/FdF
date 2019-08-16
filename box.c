
#include "libft.h"
#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "config.h"

t_box		*new_box()
{
	t_box *new;

	new = (t_box*)malloc(sizeof(t_box));
	return (new);
}

static void	put_vert_b_new(t_dot *dot, t_param *param, int rows, t_box **box)
{
	t_dot	*dotp;
	t_box	*tmp;

	dotp = dot;
	while (dotp->next && (rows))
	{
		dotp = dotp->next;
		rows--;
	}
	while (dotp->next && dot->next)
	{
		if (dot->row == dot->next->row)
		{
			tmp = new_box();
			tmp->dot1 = create_dot(dot->x, dot->y, dot->z, dot->color);
			tmp->dot2 = create_dot(dotp->x, dotp->y, dotp->z, dotp->color);
			tmp->dot3 = create_dot(dot->next->x, dot->next->y, dot->next->z, dot->next->color);
			tmp->dot4 = create_dot(dotp->next->x, dotp->next->y, dotp->next->z, dotp->next->color);
			tmp->ctr = ((dot->dep + dotp->dep + dot->next->dep + dotp->next->dep) / 4);
			add_box(box, tmp);
		}
		dot = dot->next;
		dotp = dotp->next;
	}
}

void		fill_dot()
{

}

void		fill_box_info(t_param *param)
{

}

t_box		*create_box(t_param *param)
{
	t_dot	*tmp;
	int		n_rows;
	t_dot	*dot;
	t_box	*new;

	dot = param->dot;
	n_rows = 1;
	tmp = dot;
	new = NULL;
	while (dot->next)
	{
		if (dot->row == dot->next->row)
			n_rows++;
		else
			n_rows = 1;
		dot = dot->next;
	}
	put_vert_b_new(tmp, param, n_rows, &new);
	return (new);
}


void		swap_box(t_box *box1, t_box *box2)
{
	t_dot	*d1;
	t_dot	*d2;
	t_dot	*d3;
	t_dot	*d4;
	int	ctr;

	d1 = box1->dot1;
	d2 = box1->dot2;
	d3 = box1->dot3;
	d4 = box1->dot4;
	ctr = box1->ctr;
	box1->dot1 = box2->dot1;
	box1->dot2 = box2->dot2;
	box1->dot3 = box2->dot3;
	box1->dot4 = box2->dot4;
	box1->ctr = box2->ctr;
	box2->dot1 = d1;
	box2->dot2 = d2;
	box2->dot3 = d3;
	box2->dot4 = d4;
	box2->ctr = ctr;
}


void		sort_box(t_box *box)
{
	t_box	*tmpi;
	t_box	*tmpj;
	t_box	*tmps;

	tmpi = box;
	while (tmpi)
	{
		tmpj = box;
		while (tmpj->next)
		{
			if (tmpj->ctr > tmpj->next->ctr)
				swap_box(tmpj, tmpj->next);
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
}

void		draw_box_new(t_param *param, t_box *box, char diags)
{
	while (box)
	{
		draw_box_n(param, box->dot1, box->dot2, box->dot3, 0);
		draw_box_n(param, box->dot2, box->dot1, box->dot4, 0);
		draw_box_n(param, box->dot3, box->dot1, box->dot4, 0);
		draw_box_n(param, box->dot4, box->dot2, box->dot3, 0);
		draw_line_t(param, box->dot1, box->dot2);
		draw_line_t(param, box->dot1, box->dot3);
		draw_line_t(param, box->dot3, box->dot4);
		draw_line_t(param, box->dot2, box->dot4);
		if (diags)
		{
			draw_line_t(param, box->dot1, box->dot4);
			draw_line_t(param, box->dot3, box->dot2);
		}
		box = box->next;
	}
}
