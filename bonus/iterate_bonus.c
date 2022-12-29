/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:01:15 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:01:19 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_iteration	iterate(t_point z, t_point c, t_env *env)
{
	t_iteration	iter;

	iter.iteration = -1;
	iter.max_iteration = env->max_iteration;
	while (++iter.iteration < iter.max_iteration)
	{
		z = create_point(
				z.x * z.x - z.y * z.y + c.x,
				2 * z.x * z.y + c.y
				);
		if (z.x * z.x + z.y * z.y >= 4)
			break ;
	}
	return (iter);
}

t_iteration	iterate_p3(t_point z, t_point c, t_env *env)
{
	t_iteration	iter;

	iter.iteration = -1;
	iter.max_iteration = env->max_iteration;
	while (++iter.iteration < iter.max_iteration)
	{
		z = create_point(
				z.x * z.x * z.x - 3 * z.x * z.y * z.y + c.x,
				3 * z.x * z.x * z.y - z.y * z.y * z.y + c.y
				);
		if (z.x * z.x + z.y * z.y >= 4)
			break ;
	}
	return (iter);
}

t_iteration	iterate_p1(t_point z, t_point c, t_env *env)
{
	t_iteration	iter;

	iter.iteration = -1;
	iter.max_iteration = env->max_iteration;
	while (++iter.iteration < iter.max_iteration)
	{
		z = create_point(
				powl(z.x, 5) - 10 * powl(z.x, 3) * powl(z.y, 2)
				+ 5 * z.x * powl(z.y, 4) + c.x,
				5 * powl(z.x, 4) * z.y - 10 * powl(z.x, 2)
				* powl(z.y, 3) + powl(z.y, 5) + c.y
				);
		if (z.x * z.x + z.y * z.y >= 4)
			break ;
	}
	return (iter);
}
