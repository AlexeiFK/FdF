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

void	str_to_dots(char **split, t_dot **dots)
{
	static int	col = 0;
	int			x;
	int			i;
	t_dot		*tmp;

	x = 0;
	while (split[x] != NULL)
	{
		tmp = create_dot(x, col, ft_atoi(split[x]), 0xFFFFFF);
		tmp->row = col;
		add_dot(dots, tmp);
		x++;
	}
	col++;
}

t_dot	*ft_cpy(t_dot *dot)
{
	t_dot	*tmp;
	t_dot	*new;

	while (dot)
	{
		tmp = create_dot(dot->x, dot->y, dot->z, dot->color);
		tmp->row = dot->row;
		add_dot(&new, tmp);
		dot = dot->next;
	}
	return (new);
}

t_dot	*ft_reader(char *filename)
{
	int		fd;
	char	*str;
	char	**split;
	int		ret;
	t_dot	*dots;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		split = ft_strsplit(str, ' ');
		free(str);
		str_to_dots(split, &dots);
		free(split); // normalnii free dlya char**
	}
	return (dots);
}
