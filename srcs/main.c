/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:12:45 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 10:12:45 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*data_init3(t_data *i, int w, int h, void *mlx)
{
	i[45].img = mlx_xpm_file_to_image(mlx, "img/poop_f2.xpm", &w, &h);
	i[46].img = mlx_xpm_file_to_image(mlx, "img/poop_f3.xpm", &w, &h);
	i[47].img = mlx_xpm_file_to_image(mlx, "img/poop_f4.xpm", &w, &h);
	i[48].img = mlx_xpm_file_to_image(mlx, "img/poop_f5.xpm", &w, &h);
	i[49].img = mlx_xpm_file_to_image(mlx, "img/head1.xpm", &w, &h);
	i[50].img = mlx_xpm_file_to_image(mlx, "img/head2.xpm", &w, &h);
	i[51].img = mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h);
	i[52].img = mlx_xpm_file_to_image(mlx, "img/1.xpm", &w, &h);
	i[53].img = mlx_xpm_file_to_image(mlx, "img/2.xpm", &w, &h);
	i[54].img = mlx_xpm_file_to_image(mlx, "img/3.xpm", &w, &h);
	i[55].img = mlx_xpm_file_to_image(mlx, "img/4.xpm", &w, &h);
	i[56].img = mlx_xpm_file_to_image(mlx, "img/5.xpm", &w, &h);
	i[57].img = mlx_xpm_file_to_image(mlx, "img/6.xpm", &w, &h);
	i[58].img = mlx_xpm_file_to_image(mlx, "img/7.xpm", &w, &h);
	i[59].img = mlx_xpm_file_to_image(mlx, "img/8.xpm", &w, &h);
	i[60].img = mlx_xpm_file_to_image(mlx, "img/9.xpm", &w, &h);
	i[61].img = mlx_xpm_file_to_image(mlx, "img/2point.xpm", &w, &h);
	i[62].img = mlx_xpm_file_to_image(mlx, "img/fly_1.xpm", &w, &h);
	i[63].img = mlx_xpm_file_to_image(mlx, "img/fly_2.xpm", &w, &h);
	i[64].img = mlx_xpm_file_to_image(mlx, "img/fly_3.xpm", &w, &h);
	i[65].img = mlx_xpm_file_to_image(mlx, "img/fly_4.xpm", &w, &h);
	i[66].img = mlx_xpm_file_to_image(mlx, "img/fly_5.xpm", &w, &h);
	return (i);
}

t_data	*data_init2(t_data *i, int w, int h, void *mlx)
{
	i[22].img = mlx_xpm_file_to_image(mlx, "img/wall_down.xpm", &w, &h);
	i[23].img = mlx_xpm_file_to_image(mlx, "img/wall_left.xpm", &w, &h);
	i[24].img = mlx_xpm_file_to_image(mlx, "img/wall_right.xpm", &w, &h);
	i[25].img = mlx_xpm_file_to_image(mlx, "img/collectible.xpm", &w, &h);
	i[26].img = mlx_xpm_file_to_image(mlx, "img/exit_close.xpm", &w, &h);
	i[27].img = mlx_xpm_file_to_image(mlx, "img/ui_heart.xpm", &w, &h);
	i[28].img = mlx_xpm_file_to_image(mlx, "img/ui_heart2.xpm", &w, &h);
	i[29].img = mlx_xpm_file_to_image(mlx, "img/ui_heart3.xpm", &w, &h);
	i[30].img = mlx_xpm_file_to_image(mlx, "img/tears.xpm", &w, &h);
	i[31].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	i[32].img = mlx_xpm_file_to_image(mlx, "img/body_r1.xpm", &w, &h);
	i[33].img = mlx_xpm_file_to_image(mlx, "img/body_r2.xpm", &w, &h);
	i[34].img = mlx_xpm_file_to_image(mlx, "img/body_r3.xpm", &w, &h);
	i[35].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	i[36].img = mlx_xpm_file_to_image(mlx, "img/body_l1.xpm", &w, &h);
	i[37].img = mlx_xpm_file_to_image(mlx, "img/body_l2.xpm", &w, &h);
	i[38].img = mlx_xpm_file_to_image(mlx, "img/body_l3.xpm", &w, &h);
	i[39].img = mlx_xpm_file_to_image(mlx, "img/head3.xpm", &w, &h);
	i[40].img = mlx_xpm_file_to_image(mlx, "img/head5.xpm", &w, &h);
	i[41].img = mlx_xpm_file_to_image(mlx, "img/head7.xpm", &w, &h);
	i[42].img = mlx_xpm_file_to_image(mlx, "img/head8.xpm", &w, &h);
	i[43].img = mlx_xpm_file_to_image(mlx, "img/head4.xpm", &w, &h);
	i[44].img = mlx_xpm_file_to_image(mlx, "img/head6.xpm", &w, &h);
	return (data_init3(i, w, h, mlx));
}

t_data	*data_init(t_data *i, int w, int h, void *mlx)
{
	i = malloc(67 * sizeof(t_data));
	i[0].img = mlx_xpm_file_to_image(mlx, "img/poop_f1.xpm", &w, &h);
	i[1].img = mlx_xpm_file_to_image(mlx, "img/wall1.xpm", &w, &h);
	i[2].img = mlx_xpm_file_to_image(mlx, "img/wall2.xpm", &w, &h);
	i[3].img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	i[4].img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	i[5].img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &w, &h);
	i[6].img = mlx_xpm_file_to_image(mlx, "img/standing_d.xpm", &w, &h);
	i[7].img = mlx_xpm_file_to_image(mlx, "img/head1.xpm", &w, &h);
	i[8].img = mlx_xpm_file_to_image(mlx, "img/head2.xpm", &w, &h);
	i[9].img = mlx_xpm_file_to_image(mlx, "img/body.xpm", &w, &h);
	i[10].img = mlx_xpm_file_to_image(mlx, "img/body_d1.xpm", &w, &h);
	i[11].img = mlx_xpm_file_to_image(mlx, "img/body_d2.xpm", &w, &h);
	i[12].img = mlx_xpm_file_to_image(mlx, "img/body_d3.xpm", &w, &h);
	i[13].img = mlx_xpm_file_to_image(mlx, "img/body_succes.xpm", &w, &h);
	i[14].img = mlx_xpm_file_to_image(mlx, "img/i_floor_l", &w, &h);
	i[15].img = mlx_xpm_file_to_image(mlx, "img/i_floor_r", &w, &h);
	i[16].img = mlx_xpm_file_to_image(mlx, "img/Wcorner_UL.xpm", &w, &h);
	i[17].img = mlx_xpm_file_to_image(mlx, "img/Wcorner_UR.xpm", &w, &h);
	i[18].img = mlx_xpm_file_to_image(mlx, "img/Wcorner_DL.xpm", &w, &h);
	i[19].img = mlx_xpm_file_to_image(mlx, "img/Wcorner_DR.xpm", &w, &h);
	i[20].img = mlx_xpm_file_to_image(mlx, "img/exit_open.xpm", &w, &h);
	i[21].img = mlx_xpm_file_to_image(mlx, "img/wall_up.xpm", &w, &h);
	return (data_init2(i, w, h, mlx));
}

int	game_time(t_vars *v)
{
	static int	first;

	if (!(v->time % 5000) || !first)
	{
		first++;
		system("afplay sound/the_caves.wav -t 100 &");
	}
	display_map(v, v->map.map);
	usleep(10000);
	if (!(v->time++ % 50))
		vars_ui_timer(v);
	if (!(v->time % 500) && v->player.hp > 0)
	{
		system("afplay sound/baby_hurt_1.wav &");
		v->player.hp--;
	}
	if (!(v->time % 3))
		v->sprites[5] = v->sprites[5]->next;
	if (v->event == v->time && v->event > 0)
		v->map.images[7] = v->map.images[67];
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		return (argument_error());
	vars.map.map = get_map(argv[1]);
	if (!vars.map.map)
		return (-1);
	vars.map.nb_collectibles = nb_collectible(vars.map);
	vars.map.exits = exits(vars.map.map);
	if (check_error(&(vars.map)) == -1)
		return (-1);
	vars.map.data_size = 42;
	if (init_game(&vars.player, vars.map) == -1)
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * vars.map.data_size,
			vars.map.height * vars.map.data_size, "so_long");
	vars.map.images = data_init(vars.map.images,
			vars.map.data_size, vars.map.data_size, vars.mlx);
	set_vars(&vars);
	mlx_loop_hook(vars.mlx, game_time, &vars);
	mlx_hook(vars.win, 17, 0, destroy, &vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
