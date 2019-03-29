/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/29 22:11:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_line;

typedef struct		s_dot
{
	int		x;
	int		y;
}					t_dot;

t_line	*create_line(int start_x, int start_y, int end_x, int end_y);
t_line	*create_line_d(t_dot *start_dot, t_dot *end_dot);
t_dot	*create_dot(int x, int y);
void	free_dot(t_line *line);
void	free_line(t_dot *dot);

void	draw_line(void *mlx_ptr, void *win_ptr, t_line *line, int color);

#endif
