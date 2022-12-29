/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:45:48 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/30 22:21:51 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../mlx/mlx.h"
# include <math.h>
# include "../libft/libft.h"

# define HEIGHT 		500
# define WIDTH 			500

# define MAX_ITER 		50
# define MOVEMENT_SPEED .2
# define SCALING_FACTOR 1.09

# define SCROLL_UP		5
# define SCROLL_DOWN	4

# define KEY_H			4
# define KEY_R			15
# define KEY_P			35
# define KEY_J			38
# define KEY_ESC		53
# define NUMPAD_PLUS	69
# define NUMPAD_MINUS	78
# define NUMPAD_0		82
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126

# define TEXT_COLOR		0x808080

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_img;

typedef struct s_point
{
	long double		x;
	long double		y;
}	t_point;

typedef struct s_iteration
{
	int				iteration;
	int				max_iteration;
}	t_iteration;

typedef struct s_render
{
	int				is_render;
}	t_render;

typedef struct s_env
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	char			**argv;
	int				argc;
	long double		scale;
	long double		max_iteration;
	long double		dx;
	long double		dy;
	void			(*set)();
	t_iteration		(*iter)();
	unsigned int	(*ploter)();
	t_render		render;
	t_point			z;
	t_point			c;
	t_point			mouse_pos;
	t_point			mouse_point;
	t_point			center;
	int				pause;
}	t_env;

// utils
void				mandelbrot(t_env *e);
void				julia(t_env *e);

t_iteration			iterate(t_point z, t_point c, t_env *env);
t_iteration			iterate_burningship(t_point z, t_point c, t_env *env);
t_iteration			iterate_p3(t_point z, t_point c, t_env *env);
t_iteration			iterate_p1(t_point z, t_point c, t_env *env);

void				put_pixel(t_img *data, int x, int y, int color);
unsigned int		color_trip(int iter, t_env *env);
unsigned int		color_redmoon(int iter, t_env *env);
unsigned int		color_lsd(int iter, t_env *env);
unsigned int		color_white(int iter, t_env *env);

t_point				get_mouse_pos(t_env *env);
t_point				pixel_to_point(t_point pixel, t_env *env);
t_point				create_point(double x, double y);

int					awake(t_env *env);
int					start(t_env *env);
int					update(t_env *env);

int					on_gui(t_env *env);
int					on_trigger(int keycode, t_env *env);
int					on_mouse(int button, int x, int y, t_env *env);
int					on_application_quit(t_env *env);

void				print_help(int fd);
void				print_usage(int fd);
void				error_exit(void);
int					parse_arg(int argc, char **argv, t_env *env);

#endif
