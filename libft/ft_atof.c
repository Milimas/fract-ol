/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:54:31 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/27 18:54:34 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long double	ft_atof(const char *str)
{
	long double	num;
	long double	fract;
	char		*s;
	int			sign;

	sign = 1;
	if (*str == '-')
		sign *= -1;
	s = (char *)str;
	num = ft_atoi(str);
	fract = 0;
	s = ft_strchr(s, '.');
	if (s && *s == '.')
	{
		fract = ft_atoi(s + 1);
		while (ft_isdigit(*(++s)))
			fract /= 10;
	}
	return (num + sign * fract);
}
