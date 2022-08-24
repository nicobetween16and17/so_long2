/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:47:19 by niespana          #+#    #+#             */
/*   Updated: 2022/08/24 11:47:20 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	issues(int argc, t_vars *v, char **argv)
{
	if (argc != 2)
		return (argument_error());
	v->map.map = get_map(argv[1]);
	if (!v->map.map && ft_printf("Empty map error\n"))
		return (1);
	v->map.nb_collectibles = nb_collectible(v->map);
	v->map.exits = exits(v->map.map);
	if (check_error(&(v->map)) == -1)
		return (1);
	v->map.data_size = 42;
	set_vars(v);
	if (init_game(&v->player, &(v->map)) == -1)
		return (1);
	if (!avaible_path(v->map.map, -1, -1, v->player.cp)
		&& ft_printf("No paths avaible error\n"))
		return (1);
	return (0);
}
