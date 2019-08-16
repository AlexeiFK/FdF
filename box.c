/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:19:21 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 18:47:54 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		free_box(t_box **box)
{
	t_box	*tmp;
	t_box	*btf;

	btf = *box;
	while (btf)
	{
		tmp = btf->next;
		free(btf->dot1);
		free(btf->dot2);
		free(btf->dot3);
		free(btf->dot4);
		free(btf);
		btf = tmp;
	}
	*box = NULL;
}

static void	setup_box_info(t_dot *dot, int rows, t_box **box)
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
	setup_box_info(tmp, n_rows, &new);
	return (new);
}


