/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_gui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:09:32 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:09:34 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	on_gui(t_env *env)
{
	env->mouse_point = pixel_to_point(env->mouse_pos, env);
	return (0);
}
