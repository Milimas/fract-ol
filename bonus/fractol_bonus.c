/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:12:59 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 16:13:02 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	awake(t_env *env)
{
	t_img	img;

	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fractol");
	img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	env->img = img;
	return (0);
}

int	start(t_env *env)
{
	(void)env;
	env->center.x = 0;
	env->center.y = 0;
	env->scale = 1;
	env->max_iteration = MAX_ITER;
	env->render.is_render = 1;
	env->dx = WIDTH / 4;
	env->dy = HEIGHT / 4;
	env->c.x = 0;
	env->c.y = 0;
	env->ploter = color_redmoon;
	return (0);
}

int	on_application_quit(t_env *env)
{
	(void)env;
	mlx_destroy_window(env->mlx, env->mlx_win);
	exit(0);
	return (0);
}

int	loop_hook(t_env *env)
{
	int	x;
	int	y;

	if (!env->pause)
	{
		mlx_mouse_get_pos(env->mlx_win, &x, &y);
		env->mouse_pos.x = x;
		env->mouse_pos.y = y;
		env->mouse_point = pixel_to_point(env->mouse_pos, env);
		env->c = env->mouse_point;
		env->render.is_render = 1;
	}
	if (env->render.is_render)
	{
		if (env->ploter != color_lsd)
			mlx_clear_window(env->mlx, env->mlx_win);
		update(env);
		on_gui(env);
		mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
		env->render.is_render = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	start(&env);
	parse_arg(argc, argv, &env);
	awake(&env);
	mlx_key_hook(env.mlx_win, on_trigger, &env);
	mlx_mouse_hook(env.mlx_win, on_mouse, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_hook(env.mlx_win, 17, 0, on_application_quit, &env);
	mlx_loop(env.mlx);
	return (0);
}
