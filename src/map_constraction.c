/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman <ayaman@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:46:42 by yerkiral          #+#    #+#             */
/*   Updated: 2022/09/01 18:56:15 by ayman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*put_line(char *buffer, int *bf)
{
	char	*line;
	int		buffer_index;
	int		line_length;
	int		index;

	buffer_index = (*bf);
	line_length = 0;
	index = buffer_index;
	while (buffer[buffer_index] != '\n' && buffer[buffer_index] != '\0')
	{
		line_length++;
		buffer_index++;
	}
	(*bf) += line_length + 1;
	buffer_index = index;
	index = 0;
	line = (char *) malloc(sizeof(char) * (line_length + 1));
	while (index < line_length)
		line[index++] = buffer[buffer_index++];
	line[index] = '\0';
	return (line);
}

static int	count_nl(char *buffer, int size)
{
	int	enter;
	int	i;

	i = 0;
	enter = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

static char	**map_builder(char *buffer, int size, t_game *sl)
{
	int		enter;
	int		index;
	int		bf;
	char	**map;

	index = 0;
	bf = 0;
	enter = count_nl(buffer, size);
	sl->map_height = enter;
	map = (char **) malloc(sizeof(char *) * enter);
	while (index < enter)
	{
		map[index] = put_line(buffer, &bf);
		index++;
	}
	return (map);
}

char	**map_constractor(t_game *sl, int fd)
{
	char	buffer[10000];
	int		i;
	int		bytes;

	bytes = 1;
	i = 0;
	ft_reset(buffer);
	while (bytes)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
		{
			free(sl);
			exit(1);
		}
		i++;
	}
	return (map_builder(buffer, i, sl));
}
