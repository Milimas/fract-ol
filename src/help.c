/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:45 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 16:57:47 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(int fd)
{
	ft_putendl_fd("usage: fractol <set> [-c x y] [-z number] [-m number] [-p palette] | \
[-h | --help]", fd);
	ft_putendl_fd("\t<set>: {mandelbrot | mandelbrot1 | \
mandelbrot3 | julia | burningship}", fd);
	ft_putendl_fd("\t-c x y: center point where x and y \
are float numbers between (-2, 2)", fd);
	ft_putendl_fd("\t-z number: zoom where number is a float number > 0", fd);
	ft_putendl_fd("\t-m number: max iteration where number \
is a float number > 0", fd);
	ft_putendl_fd("\t-p palette: color palette {redmoon | \
white | trip | lsd}", fd);
	ft_putendl_fd("\t-h or --help: to display this message", fd);
	exit(EXIT_FAILURE);
}

void	print_help(int fd)
{
	ft_putendl_fd("keys:", fd);
	ft_putendl_fd("\tp\tpause julia set", fd);
	ft_putendl_fd("\tj\tdisplay julia set", fd);
	ft_putendl_fd("\tr\treload set", fd);
	ft_putendl_fd("\th\tto display this message", fd);
	ft_putendl_fd("Numpad keys:", fd);
	ft_putendl_fd("\t0\treset zoom", fd);
	ft_putendl_fd("\t+\tincrease iteration", fd);
	ft_putendl_fd("\t-\tdecrease iteration", fd);
	ft_putendl_fd("Arrow keys:", fd);
	ft_putendl_fd("\tup\tmove up", fd);
	ft_putendl_fd("\tdown\tmove down", fd);
	ft_putendl_fd("\tright\tmove right", fd);
	ft_putendl_fd("\tleft\tmove left", fd);
	ft_putendl_fd("Mouse:", fd);
	ft_putendl_fd("\tscroll up\tzoom in", fd);
	ft_putendl_fd("\tscroll down\tzoom out", fd);
}

void	error_exit(void)
{
	print_usage(STDERR_FILENO);
}
