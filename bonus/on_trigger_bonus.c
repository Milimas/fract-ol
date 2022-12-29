/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_trigger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:12:40 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:12:42 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	on_move(int keycode, t_env *env)
{
	if (keycode == KEY_LEFT)
		env->center.x -= MOVEMENT_SPEED * 1 / env->scale;
	if (keycode == KEY_RIGHT)
		env->center.x += MOVEMENT_SPEED * 1 / env->scale;
	if (keycode == KEY_DOWN)
		env->center.y -= MOVEMENT_SPEED * 1 / env->scale;
	if (keycode == KEY_UP)
		env->center.y += MOVEMENT_SPEED * 1 / env->scale;
	return (0);
}

static int	on_numpad(int keycode, t_env *env)
{
	if (keycode == NUMPAD_PLUS)
		env->max_iteration += 10;
	if (keycode == NUMPAD_MINUS)
		env->max_iteration -= 10 * !!(env->max_iteration > 20);
	if (keycode == NUMPAD_0 || keycode == KEY_J)
	{
		env->center.x = 0;
		env->center.y = 0;
		env->scale = 1;
	}
	return (0);
}

int	on_trigger(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		on_application_quit(env);
	on_move(keycode, env);
	on_numpad(keycode, env);
	if (keycode == KEY_J)
		env->set = julia;
	if (keycode == KEY_R)
		parse_arg(start(env) + env->argc, env->argv, env);
	if (keycode == KEY_P)
		env->pause = !env->pause;
	if (keycode == KEY_H)
		print_help(STDOUT_FILENO);
	env->render.is_render = 1;
	return (0);
}
