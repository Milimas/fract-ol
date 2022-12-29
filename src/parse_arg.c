/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:13:25 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 17:13:27 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_set(t_env *env, void (*set)(), t_iteration (iter)())
{
	env->set = set;
	env->iter = iter;
}

int	parse_set(char **argv, t_env *env)
{
	if (!ft_strncmp("julia", argv[1], ft_strlen(argv[1]) + 1))
		init_set(env, julia, iterate);
	else if (!ft_strncmp("mandelbrot", argv[1], ft_strlen(argv[1]) + 1))
		init_set(env, mandelbrot, iterate);
	else if (!ft_strncmp("burningship", argv[1], ft_strlen(argv[1]) + 1))
		init_set(env, mandelbrot, iterate_burningship);
	else if (!ft_strncmp("mandelbrot3", argv[1], ft_strlen(argv[1]) + 1))
		init_set(env, mandelbrot, iterate_p3);
	else if (!ft_strncmp("mandelbrot1", argv[1], ft_strlen(argv[1]) + 1))
		init_set(env, mandelbrot, iterate_p1);
	else
		error_exit();
	return (0);
}

void	*get_color(char *str)
{
	size_t	size;

	size = ft_strlen(str) + 1;
	if (!ft_strncmp(str, "white", size))
		return (color_white);
	if (!ft_strncmp(str, "lsd", size))
		return (color_lsd);
	if (!ft_strncmp(str, "redmoon", size))
		return (color_redmoon);
	if (!ft_strncmp(str, "trip", size))
		return (color_trip);
	else
		error_exit();
	return (0);
}

int	parse_set_arg(int argc, char **argv, t_env *env)
{
	while (--argc > 0)
	{
		if (!ft_strncmp(argv[env->argc - argc], "-c", 3) && argc > 2)
		{
			env->c.x = ft_atof(argv[env->argc - --argc]);
			env->c.y = -ft_atof(argv[env->argc - --argc]);
			env->center.x = env->c.x * !(env->set == julia);
			env->center.y = -env->c.y * !(env->set == julia);
			env->pause = (env->set == julia);
		}
		else if (!ft_strncmp(argv[env->argc - argc], "-z", 3) && argc > 1)
			env->scale = 1 / ft_atof(argv[env->argc - --argc]);
		else if (!ft_strncmp(argv[env->argc - argc], "-m", 3) && argc > 1)
			env->max_iteration = ft_atof(argv[env->argc - --argc]);
		else if (!ft_strncmp(argv[env->argc - argc], "-p", 3) && argc > 1)
			env->ploter = get_color(argv[env->argc - --argc]);
		else
			error_exit();
		if (env->max_iteration < 1 || env->scale == INFINITY)
			error_exit();
	}
	return (0);
}

int	parse_arg(int argc, char **argv, t_env *env)
{
	env->argv = argv;
	env->argc = argc;
	if (argc > 1)
	{
		parse_set(argv, env);
		argc--;
		parse_set_arg(argc, argv, env);
	}
	else
		error_exit();
	return (0);
}
