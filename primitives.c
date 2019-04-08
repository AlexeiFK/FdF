/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:31:53 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 23:34:48 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_dot	*create_dot(int x, int y, int z, int color)
{
	t_dot		*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->z = z;
	dot->color = color;
	dot->next = NULL;
	return (dot);
}

void	add_dot(t_dot **dot, t_dot *new)
{
	if (!dot || !new)
		return ;
	new->next = *dot;
	*dot = new;
}

void	iter_dot(t_dot *dot, void (*f)(t_dot *elem))
{
	while (dot)
	{
		(*f)(dot);
		dot = dot->next;
	}
}

void	free_dot(t_dot **dot)
{
	t_dot	*tmp;
	t_dot	*dtr;

	dtr = *dot;
	while (dtr)
	{
		tmp = dtr->next;
		free(dtr);
		dtr = tmp;
	}
	*dot = NULL;
}

void	free_line(t_dot *dot)
{
}
