/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:06:17 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:06:19 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia(t_env *env)
{
	t_point		pt;
	long double	sx;
	long double	sy;

	sx = 1 / env->scale;
	sy = HEIGHT / (WIDTH * env->scale);
	pt.x = -1;
	while (++pt.x < WIDTH)
	{
		pt.y = -1;
		env->z.x = (pt.x / env->dx - 2) * sx + env->center.x;
		while (++pt.y < HEIGHT)
		{
			env->z.y = (pt.y / env->dy - 2) * sy - env->center.y;
			put_pixel(&env->img, pt.x, pt.y,
				env->ploter(env->iter(env->z, env->c, env).iteration, env));
		}
	}
}
