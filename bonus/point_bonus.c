/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:15:08 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:15:11 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_point	create_point(double x, double y)
{
	t_point	poit_point;

	poit_point.x = x;
	poit_point.y = y;
	return (poit_point);
}
