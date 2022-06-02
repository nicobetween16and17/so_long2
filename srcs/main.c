/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:59:06 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 12:59:07 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init2(t_map *m, int w, int h, void *mlx)
{
	m->images[14].img = mlx_xpm_file_to_image(mlx, "img/wall_d.xpm", &w, &h);
	m->images[15].img = mlx_xpm_file_to_image(mlx, "img/wall_l.xpm", &w, &h);
	m->images[16].img = mlx_xpm_file_to_image(mlx, "img/wall_r.xpm", &w, &h);
	m->images[17].img = mlx_xpm_file_to_image(mlx, "img/c.xpm", &w, &h);
	m->images[18].img = mlx_xpm_file_to_image(mlx, "img/exit_c.xpm", &w, &h);
	m->images[19].img = mlx_xpm_file_to_image(mlx, "img/ui_heart.xpm", &w, &h);
	m->images[20].img = mlx_xpm_file_to_image(mlx, "img/ui_heart2.xpm", &w, &h);
	m->images[21].img = mlx_xpm_file_to_image(mlx, "img/ui_heart3.xpm", &w, &h);
	m->images[22].img = mlx_xpm_file_to_image(mlx, "img/tears.xpm", &w, &h);
	m->images[23].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	m->images[24].img = mlx_xpm_file_to_image(mlx, "img/body_r1.xpm", &w, &h);
	m->images[25].img = mlx_xpm_file_to_image(mlx, "img/body_r2.xpm", &w, &h);
	m->images[26].img = mlx_xpm_file_to_image(mlx, "img/body_r3.xpm", &w, &h);
	m->images[27].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	m->images[28].img = mlx_xpm_file_to_image(mlx, "img/body_l1.xpm", &w, &h);
	m->images[29].img = mlx_xpm_file_to_image(mlx, "img/body_l2.xpm", &w, &h);
	m->images[30].img = mlx_xpm_file_to_image(mlx, "img/body_l3.xpm", &w, &h);
	m->images[31].img = mlx_xpm_file_to_image(mlx, "img/head3.xpm", &w, &h);
	m->images[32].img = mlx_xpm_file_to_image(mlx, "img/head5.xpm", &w, &h);
	m->images[33].img = mlx_xpm_file_to_image(mlx, "img/head7.xpm", &w, &h);
	m->images[34].img = mlx_xpm_file_to_image(mlx, "img/head8.xpm", &w, &h);
	m->images[35].img = mlx_xpm_file_to_image(mlx, "img/head4.xpm", &w, &h);
	m->images[36].img = mlx_xpm_file_to_image(mlx, "img/head6.xpm", &w, &h);
}

void	data_init(t_map *m, int w, int h, void *mlx)
{
	m->images[0].img = mlx_xpm_file_to_image(mlx, "img/poop_f1.xpm", &w, &h);
	m->images[1].img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	m->images[2].img = mlx_xpm_file_to_image(mlx, "img/head1.xpm", &w, &h);
	m->images[3].img = mlx_xpm_file_to_image(mlx, "img/head2.xpm", &w, &h);
	m->images[4].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	m->images[5].img = mlx_xpm_file_to_image(mlx, "img/body_d1.xpm", &w, &h);
	m->images[6].img = mlx_xpm_file_to_image(mlx, "img/body_d2.xpm", &w, &h);
	m->images[7].img = mlx_xpm_file_to_image(mlx, "img/body_d3.xpm", &w, &h);
	m->images[8].img = mlx_xpm_file_to_image(mlx, "img/C_UL.xpm", &w, &h);
	m->images[9].img = mlx_xpm_file_to_image(mlx, "img/C_UR.xpm", &w, &h);
	m->images[10].img = mlx_xpm_file_to_image(mlx, "img/C_DL.xpm", &w, &h);
	m->images[11].img = mlx_xpm_file_to_image(mlx, "img/C_DR.xpm", &w, &h);
	m->images[12].img = mlx_xpm_file_to_image(mlx, "img/exit_o.xpm", &w, &h);
	m->images[13].img = mlx_xpm_file_to_image(mlx, "img/wall_u.xpm", &w, &h);
	m->images[60].img = mlx_xpm_file_to_image(mlx, "img/black.xpm", &w, &h);
	m->images[61].img = mlx_xpm_file_to_image(mlx, "img/over.xpm", &w, &h);
	m->images[62].img = mlx_xpm_file_to_image(mlx, "img/dead_baby.xpm", &w, &h);
	data_init2(m, w, h, mlx);
}

int	destroy(t_vars *vars)
{
	ft_printf("endgame\n");
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	handle_input(keycode, &(vars->map), &(vars->player), vars);
	if ((is_exit(vars->player.cp, vars->map.exits)
			&& vars->player.nb_collectibles == vars->map.nb_collectibles)
		|| keycode == 53)
	{
		end_game(vars->map);
		destroy(vars);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		v;

	if (argc != 2)
		return (argument_error());
	v.map.map = get_map(argv[1]);
	if (!v.map.map)
		return (-1);
	v.map.nb_collectibles = nb_collectible(v.map);
	v.map.exits = exits(v.map.map);
	if (check_error(&(v.map)) == -1)
		return (-1);
	v.map.data_size = 42;
	if (init_game(&v.player, v.map) == -1)
		return (-1);
	v.last_pos = '0';
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, v.map.width * v.map.data_size,
			v.map.height * v.map.data_size, "so_long");
	data_init(&v.map, v.map.data_size, v.map.data_size, v.mlx);
	display_map(&v, v.map.map);
	mlx_hook(v.win, 17, 0, destroy, &v);
	mlx_hook(v.win, 2, 0, key_hook, &v);
	mlx_loop(v.mlx);
	return (0);
}
