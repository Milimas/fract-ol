/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:08:57 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/30 22:09:03 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

unsigned int	color_trip(int iter, t_env *env)
{
	if (iter == (int)env->max_iteration)
		return (0);
	return (0xFFFFFF * iter / env->max_iteration);
}

unsigned int	color_redmoon(int iter, t_env *env)
{
	if (iter == (int)env->max_iteration)
		return (0);
	return ((iter * 16 << 16) + (iter << 8) + iter * 4);
}

unsigned int	color_lsd(int iter, t_env *env)
{
	long double	s;
	long double	n;

	if (iter == (int)env->max_iteration)
		return (0);
	s = SCALING_FACTOR;
	n = 0xFFFFFFFF;
	return (fmodl(powl(powl(iter / (long double)env->max_iteration, s)
				* n, 1.5), n));
}

unsigned int	color_white(int iter, t_env *env)
{
	if (iter == (int)env->max_iteration)
		return (0);
	return (0xFFFFFF);
}
