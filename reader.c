/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 23:00:11 by rjeor-mo         ###   ########.fr       */
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
		add_dot(dots, tmp);
		x++;
	}
	col++;
}

t_dot	*ft_reader(char *filename)
{
	int		fd;
	char	*str;
	char	**split;
	int		ret;
	t_dot	*dots;

	printf("iner\n");
	printf("iner\n");
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
