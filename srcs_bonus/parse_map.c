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

static char	*lines(char *path, int BUFFER)
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

static int	invalid_element(char c, char last)
{
	static int	dups;

	if (c == last && c == '\n')
		return (ft_printf("Error: empty line in the map\n"));
	if (c == 'P')
		dups++;
	if (dups > 1)
		return (ft_printf("Error: Duplicate starting baby\n"));
	if (c != '1' && c != '\n' && c != 'E' && c != 'A'
		&& c != 'P' && c != '0' && c != 'C')
		return (ft_printf("Error: Invalid element in the map\n"));
	return (0);
}

char	**get_map(char *path)
{
	char	**map;
	char	*macro;
	int		i;
	char	last;

	i = -1;
	last = '\n';
	macro = lines(path, buffer(path));
	if (!macro && ft_printf("Error: Empty map\n"))
		return (NULL);
	while (macro[++i])
	{
		if (invalid_element(macro[i], last))
		{
			free(macro);
			return (NULL);
		}
		last = macro[i];
	}
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
