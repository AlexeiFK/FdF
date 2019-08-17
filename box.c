/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:19:21 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/17 23:11:07 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_box		*new_box(void)
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

static void	setup_box_info(t_dot *d, int rows, t_box **box, t_dot *dp)
{
	t_box	*tmp;

	dp = d;
	while (dp->next && (rows))
	{
		dp = dp->next;
		rows--;
	}
	while (dp->next && d->next)
	{
		if (d->row == d->next->row)
		{
			tmp = new_box();
			tmp->dot1 = create_dot(d->x, d->y, d->z, d->color);
			tmp->dot2 = create_dot(dp->x, dp->y, dp->z, dp->color);
			tmp->dot3 = create_dot(d->next->x,
					d->next->y, d->next->z, d->next->color);
			tmp->dot4 = create_dot(dp->next->x,
					dp->next->y, dp->next->z, dp->next->color);
			tmp->ctr = ((d->dep + dp->dep + d->next->dep + dp->next->dep) / 4);
			add_box(box, tmp);
		}
		d = d->next;
		dp = dp->next;
	}
}

t_box		*create_box(t_param *param)
{
	t_dot	*tmp;
	int		n_rows;
	t_dot	*dot;
	t_box	*new;
	t_dot	*norminate;

	norminate = NULL;
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
	setup_box_info(tmp, n_rows, &new, norminate);
	return (new);
}
