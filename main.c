/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:22 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 15:33:23 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

t_data 	*data_init(t_data *images, int w, int h, void *mlx)
{
	images = malloc(22 * sizeof(t_data));
	images[0].img = mlx_xpm_file_to_image(mlx, "img/walls2.xpm", &w, &h);
	images[1].img = mlx_xpm_file_to_image(mlx, "img/walls.xpm", &w, &h);
	images[2].img = mlx_xpm_file_to_image(mlx, "img/wall3.xpm", &w, &h);
	images[3].img = mlx_xpm_file_to_image(mlx, "img/sol_1.xpm", &w, &h);
	images[4].img = mlx_xpm_file_to_image(mlx, "img/sol_2.xpm", &w, &h);
	images[5].img = mlx_xpm_file_to_image(mlx, "img/sol_3.xpm", &w, &h);
	images[6].img = mlx_xpm_file_to_image(mlx, "img/sprite5.xpm", &w, &h);
	images[7].img = mlx_xpm_file_to_image(mlx, "img/sprite6.xpm", &w, &h);
	images[8].img = mlx_xpm_file_to_image(mlx, "img/sprite1.xpm", &w, &h);
	images[9].img = mlx_xpm_file_to_image(mlx, "img/sprite2.xpm", &w, &h);
	images[10].img = mlx_xpm_file_to_image(mlx, "img/sprite3.xpm", &w, &h);
	images[11].img = mlx_xpm_file_to_image(mlx, "img/sprite4.xpm", &w, &h);
	images[12].img = mlx_xpm_file_to_image(mlx, "img/border1.xpm", &w, &h);
	images[13].img = mlx_xpm_file_to_image(mlx, "img/border2.xpm", &w, &h);
	images[14].img = mlx_xpm_file_to_image(mlx, "img/border3.xpm", &w, &h);
	images[15].img = mlx_xpm_file_to_image(mlx, "img/border4.xpm", &w, &h);
	images[16].img = mlx_xpm_file_to_image(mlx, "img/coin1.xpm", &w, &h);
	images[17].img = mlx_xpm_file_to_image(mlx, "img/coin2.xpm", &w, &h);
	images[18].img = mlx_xpm_file_to_image(mlx, "img/coin3.xpm", &w, &h);
	images[19].img = mlx_xpm_file_to_image(mlx, "img/coin4.xpm", &w, &h);
	images[20].img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &w, &h);
	images[21].img = mlx_xpm_file_to_image(mlx, "img/collectible.xpm", &w, &h);
	return (images);
}
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(1);
	printf("Hello from key_hook! %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data *images;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	vars.map.images = data_init(vars.map.images, 18, 18, vars.mlx);
	printf("%s\n", vars.map.images[0].img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.map.images[0].img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
