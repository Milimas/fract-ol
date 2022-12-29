/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:11:33 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:11:34 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	on_mouse(int button, int x, int y, t_env *env)
{
	env->mouse_pos.x = x;
	env->mouse_pos.y = y;
	get_mouse_pos(env);
	if (button == SCROLL_UP)
	{
		env->max_iteration += 1;
		env->scale *= SCALING_FACTOR;
		env->center.x -= env->mouse_point.x * (1 - SCALING_FACTOR);
		env->center.y += env->mouse_point.y * (1 - SCALING_FACTOR);
		env->center.x /= SCALING_FACTOR;
		env->center.y /= SCALING_FACTOR;
	}
	if (button == SCROLL_DOWN && env->scale > 1)
	{
		env->max_iteration -= 1 * !!(env->max_iteration > 10);
		env->scale /= SCALING_FACTOR;
		env->center.x *= SCALING_FACTOR;
		env->center.y *= SCALING_FACTOR;
		env->center.x += env->mouse_point.x * (1 - SCALING_FACTOR);
		env->center.y -= env->mouse_point.y * (1 - SCALING_FACTOR);
	}
	if (button == 1)
		env->c = env->mouse_point;
	env->render.is_render = 1;
	return (0);
}
