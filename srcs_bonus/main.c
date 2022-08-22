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

#include "../includes/so_long.h"

void	data_init3(t_map *m, int w, int h, void *mlx)
{
	m->images[37].img = mlx_xpm_file_to_image(mlx, "img/poop_f2.xpm", &w, &h);
	m->images[38].img = mlx_xpm_file_to_image(mlx, "img/poop_f3.xpm", &w, &h);
	m->images[39].img = mlx_xpm_file_to_image(mlx, "img/poop_f4.xpm", &w, &h);
	m->images[40].img = mlx_xpm_file_to_image(mlx, "img/poop_f5.xpm", &w, &h);
	m->images[41].img = mlx_xpm_file_to_image(mlx, "img/head1.xpm", &w, &h);
	m->images[42].img = mlx_xpm_file_to_image(mlx, "img/head2.xpm", &w, &h);
	m->images[43].img = mlx_xpm_file_to_image(mlx, "img/0.xpm", &w, &h);
	m->images[44].img = mlx_xpm_file_to_image(mlx, "img/1.xpm", &w, &h);
	m->images[45].img = mlx_xpm_file_to_image(mlx, "img/2.xpm", &w, &h);
	m->images[46].img = mlx_xpm_file_to_image(mlx, "img/3.xpm", &w, &h);
	m->images[47].img = mlx_xpm_file_to_image(mlx, "img/4.xpm", &w, &h);
	m->images[48].img = mlx_xpm_file_to_image(mlx, "img/5.xpm", &w, &h);
	m->images[49].img = mlx_xpm_file_to_image(mlx, "img/6.xpm", &w, &h);
	m->images[50].img = mlx_xpm_file_to_image(mlx, "img/7.xpm", &w, &h);
	m->images[51].img = mlx_xpm_file_to_image(mlx, "img/8.xpm", &w, &h);
	m->images[52].img = mlx_xpm_file_to_image(mlx, "img/9.xpm", &w, &h);
	m->images[53].img = mlx_xpm_file_to_image(mlx, "img/2point.xpm", &w, &h);
	m->images[54].img = mlx_xpm_file_to_image(mlx, "img/fly_1.xpm", &w, &h);
	m->images[55].img = mlx_xpm_file_to_image(mlx, "img/fly_2.xpm", &w, &h);
	m->images[56].img = mlx_xpm_file_to_image(mlx, "img/fly_3.xpm", &w, &h);
	m->images[57].img = mlx_xpm_file_to_image(mlx, "img/fly_4.xpm", &w, &h);
	m->images[58].img = mlx_xpm_file_to_image(mlx, "img/fly_5.xpm", &w, &h);
}

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
	data_init3(m, w, h, mlx);
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

int	game_time(t_vars *v)
{
	static int	first;

	if (!(v->time % 4870) || !first++)
	{
		system("ps -a|grep afplay|grep -v 'grep'|awk '{print $1}'|xargs kill -15");
		system("afplay sound/the_caves.wav -t 100 &");
	}
	if (v->fire_rate <= v->time)
		v->fire_rate = 0;
	if (!v->immune)
		take_damage(v, -1);
	display_map(v);
	usleep(10000);
	if (!(v->time++ % 50))
		vars_ui_timer(v);
	if (v->time > v->immune)
		v->immune = 0;
	if (!(v->time % 3))
		v->sprites[5] = v->sprites[5]->next;
	if (!v->dead && v->event == v->time && v->event > 0)
		v->map.images[2] = v->map.images[59];
	if (v->event == v->time && v->dead)
		destroy(v);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

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
	if (init_game(&vars.player, &vars.map) == -1)
		return (-1);
	if (!avaible_path(vars.map.map, -1, -1,vars.player.cp))
		return (0);
	exit(0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * vars.map.data_size,
			vars.map.height * vars.map.data_size, "so_long");
	data_init(&vars.map, vars.map.data_size, vars.map.data_size, vars.mlx);
	set_vars(&vars);
	display_all(&vars);
	mlx_loop_hook(vars.mlx, game_time, &vars);
	mlx_hook(vars.win, 17, 0, destroy, &vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
