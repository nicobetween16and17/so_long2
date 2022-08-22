/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:20:35 by niespana          #+#    #+#             */
/*   Updated: 2022/05/04 11:20:39 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_sens
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_sens;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_caca
{
	t_position	p;
	int			state;
}	t_caca;

typedef struct s_fly
{
	t_position	p;
	int			hp;
	t_position	h;
}	t_fly;

typedef struct s_timer
{
	int	s;
	int	m;
	int	h;
}	t_timer;

typedef struct s_tear
{
	t_position	cp;
	t_sens		s;
	int			duration;
	int			visibility;
}	t_tear;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_map
{
	char		**map;
	int			nb_collectibles;
	t_position	*exits;
	t_data		images[79];
	int			height;
	int			width;
	int			data_size;
}	t_map;

typedef struct s_player
{
	int			nb_collectibles;
	t_position	cp;
	int			nb_mooves;
	int			hp;
	int			mooving;
}	t_player;

typedef struct s_mum
{
	t_position	attack;
	int			hp;
	t_position	hitbox[5];
	int			activ[5];
}	t_mum;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_list		*tears;
	t_timer		timer;
	int			time;
	int			last_pos;
	t_list		*sprites[15];
	t_position	p;
	t_sens		direction;
	t_caca		*shits;
	t_fly		*flies;
	int			event;
	int			t;
	int			last_frame;
	int			nb_tears;
	int			immune;
	int			dead;
	int			fire_rate;
	int			delay;
	int			ev_leg;
	int			ev_eye;
	t_mum		mum;
}	t_vars;
typedef struct s_list_pos
{
	t_position			pos;
	struct s_list_pos	*next;
}t_list_pos;

int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *b, size_t length);
void		*ft_memmove(void *s1, const void *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_printf(const char *p, ...);
int			ft_print_hex(unsigned int s, int cas);
int			*ft_putnbr_base(unsigned long s, char *base, int *res);
int			ft_putnbr_fd(long n, int fd, int unsign, int *res);
int			ft_putstr_fd(char *s, int fd);
int			ft_putchar_fd(char c, int fd, int *res);
int			ft_print_ptr(void *s);
char		**ft_split(char const *s, char c);
char		**get_map(char *lines);
int			nb_collectible(t_map map);
t_position	*exits(char **map);
int			is_exit(t_position player, t_position *list);
int			mc_error(void);
int			no_exit_error(void);
int			map_error(void);
int			wall_error(void);
int			argument_error(void);
char		**free_map_array(char **map);
int			check_error(t_map *map);
int			init_game(t_player *player, t_map *map);
void		handle_input(int keycode,
				t_map *map, t_player *player, t_vars *vars);
void		end_game(t_map map);
void		display_map(t_vars *vars);
int			random_in_range(int a, int range, int start);
void		ft_bzero(void *b, size_t length);
int			possible_moove(int key, char **map, t_position pos);
int			put_it(t_vars *vars, t_position pos, int img);
t_position	new_pos(int x, int y);
void		vars_ui_timer(t_vars *vars);
void		duration_plus_one(void *arg);
void		position_shift(void *arg);
void		tear_travel(t_vars *v, int (*f)(void *, void *, void *, int, int));
void		firing(int key, t_vars *v);
int			destroy(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
void		handle_moove(t_vars *v, int i);
void		set_direction(t_vars *v, int keycode);
void		set_vars(t_vars *v);
void		init_all_sprites(t_vars *v);
int			collision(t_position current, t_vars *v, int i, int j);
void		put_hp(t_vars *v);
int			put_shit(t_vars *v, t_position p, int i);
void		put_timer(t_vars *v);
void		put_mooves(int nb, t_vars *v);
void		enemies_travel(t_vars *v,
				int (*f)(void *, void *, void *, int, int));
void		nb_shit(t_vars *v, char **map, int *nb_shits);
void		init_cacas(t_vars *v, char **map, int nb_shits, int i_shit);
void		nb_flie(char **map, int *nb_flies);
void		init_flies(t_vars *v, char **map, int nb_flies, int i_fly);
void		set_player_pos(t_vars *v);
void		free_sprites(t_vars *v);
int			damaging(t_vars *v, t_tear *crt);
void		take_damage(t_vars *v, int i);
void		death_screen(t_vars *v);
int			set_image(t_vars *vars, t_position pos, char c);
void		display_nearby_floor(t_vars *v);
void		display_shits(t_vars *v);
void		display_walls(t_vars *v);
void		display_all(t_vars *v);
int			display_near_tears(t_vars *v, t_position tear);
void		display_under_timer(t_vars *v);
void		display_exits(t_vars *v);
void		display_under_tears(t_vars *v);
void		display_under_enemies(t_vars *v);
int			put_it2(t_vars *vars, t_position pos, int img);
int			avaible_path(char **map, int i, int j, t_position player);
#endif
