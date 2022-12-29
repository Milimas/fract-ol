/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:38 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 16:09:43 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_iteration	iterate_burningship(t_point z, t_point c, t_env *env)
{
	t_iteration	iter;

	iter.iteration = -1;
	iter.max_iteration = env->max_iteration;
	while (++iter.iteration < iter.max_iteration)
	{
		z = create_point(
				z.x * z.x - z.y * z.y + c.x,
				fabsl(2 * z.x * z.y) + c.y
				);
		if (z.x * z.x + z.y * z.y >= 4)
			break ;
	}
	return (iter);
}
