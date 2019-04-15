/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 19:37:28 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"

void	str_to_dots(char **split, t_dot **dots, t_colors *c)
{
	static int	col = 0;
	int			x;
	int			i;
	t_dot		*tmp;
	int		color_flag;

	x = 0;
	if (c == NULL)
		color_flag = 0;
	else
		color_flag = 1;
	while (split[x] != NULL)
	{
		if (color_flag)
		{
			if (ft_atoi(split[x]) == 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->mid, NULL, 16));
			else if (ft_atoi(split[x]) > 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->top, NULL, 16));
			else if (ft_atoi(split[x]) < 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->bot, NULL, 16));
		}
		else
			tmp = create_dot(x, col, ft_atoi(split[x]), 0xFFFFFF);
		tmp->row = col;
		add_dot(dots, tmp);
		x++;
	}
	col++;
}

void	ft_colorize(t_dot *dot, int max, int min)
{
	int	mid;

	mid = (max + min) / 2;

	while (dot)
	{
		dot = dot->next;
	}
}

void	ft_cpy(t_dot **new, t_dot *dot)
{
	t_dot	*tmp;

	while (dot)
	{
		tmp = create_dot(dot->x, dot->y, dot->z, dot->color);
		tmp->row = dot->row;
		add_dot(new, tmp);
//		free(tmp);
		dot = dot->next;
	}
}

t_dot	*ft_reader(char *filename, t_colors *colors)
{
	int		fd;
	char	*str;
	char	**split;
	int		ret;
	t_dot	*dots;

	dots = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		split = ft_strsplit(str, ' ');
		free(str);
		str_to_dots(split, &dots, colors);
		free(split); // normalnii free dlya char**
	}
	return (dots);
}
