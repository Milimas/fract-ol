/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:53:04 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 16:53:05 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_point	pixel_to_point(t_point pixel, t_env *env)
{
	t_point	point;

	point.x = (pixel.x / (WIDTH / 4) - 2) * 1 / env->scale + env->center.x;
	point.y = (pixel.y / (HEIGHT / 4) - 2)
		* (HEIGHT / (WIDTH * env->scale)) - env->center.y;
	return (point);
}

t_point	get_mouse_pos(t_env *env)
{
	if (env->mouse_pos.x > WIDTH)
		env->mouse_pos.x = WIDTH;
	if (env->mouse_pos.x < 0)
		env->mouse_pos.x = 0;
	if (env->mouse_pos.y > HEIGHT)
		env->mouse_pos.y = HEIGHT;
	if (env->mouse_pos.y < 0)
		env->mouse_pos.y = 0;
	env->mouse_point = pixel_to_point(env->mouse_pos, env);
	return (env->mouse_point);
}
