/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:59:38 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 12:59:39 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	buffer(char *path)
{
	int		fd;
	int		nb_bytes;
	char	reader[1];

	nb_bytes = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fd);
	while (read(fd, reader, 1))
		nb_bytes++;
	close(fd);
	return (nb_bytes);
}

char	*lines(char *path, int BUFFER)
{
	char	*lines;
	int		fd;

	lines = malloc(sizeof(char) * (BUFFER + 1));
	if (BUFFER <= 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	read(fd, lines, BUFFER);
	lines[BUFFER] = 0;
	close(fd);
	return (lines);
}

char	**get_map(char *path)
{
	char		**map;
	char		*macro;
	t_position	p;

	macro = lines(path, buffer(path));
	if (!macro)
		return (NULL);
	map = ft_split(macro, '\n');
	free(macro);
	if (!map)
		return (NULL);
	p.x = -1;
	while (map[++p.x])
	{
		p.y = -1;
		while (map[p.x][++p.y])
		{
			if (map[p.x][p.y] != 'P' && map[p.x][p.y] != '1'
				&& map[p.x][p.y] != '0' && map[p.x][p.y] != 'E'
			&& map[p.x][p.y] != 'C')
				return (free_map_array(map));
		}
	}
	return (map);
}

int	nb_collectible(t_map map)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}
