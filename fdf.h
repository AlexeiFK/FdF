/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 23:34:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_dot	*next;
}					t_dot;

t_dot	*create_dot(int x, int y, int z, int c);
void	free_dot(t_dot **dot);
t_dot	*ft_reader(char *filename);
void	add_dot(t_dot **dot, t_dot *new);
void	iter_dot(t_dot *dot, void (*f)(t_dot *elem));

void	draw_line_p(void **param, t_dot *dot1, t_dot *dot2, int color);

#endif
