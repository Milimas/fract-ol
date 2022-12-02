/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:45:48 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/30 22:21:51 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_frame
{
	t_data	*img;
	float	scale;
	float	left; 
	float	top;
	float	xside;
	float	yside;
	void	*mlx;
	void	*mlx_win;
	int		frame;
}	t_frame;

// utils
int		create_trgb(int t, int r, int g, int b);

int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
// end utils

void	put_pixel(t_data *data, int x, int y, int color);

#endif
