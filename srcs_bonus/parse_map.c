/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:13:02 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 10:13:03 by niespana         ###   ########.fr       */
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
	if (fd < 0 && argument_error())
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
	char	**map;
	char	*macro;

	macro = lines(path, buffer(path));
	if (!macro)
		return (NULL);
	map = ft_split(macro, '\n');
	if (!map)
		ft_printf("Malloc error\n");
	free(macro);
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
