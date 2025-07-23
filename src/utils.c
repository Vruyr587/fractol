/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:20:36 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 20:16:33 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}

int	check_julia_input(char *arg)
{
	int	i;

	i = 0;
	check_zeros(arg);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '.' && arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit(EXIT_FAILURE);
		i++;
	}
	if (!arg[i] && atodbl(arg) <= 2.0 && atodbl(arg) >= -2.0)
		return (1);
	while (arg[++i] && !ft_isspace(arg[i]))
		if (!ft_isdigit(arg[i]))
			exit(EXIT_FAILURE);
	while (ft_isspace(arg[i]) && arg[i])
		i++;
	if (arg[i] || atodbl(arg) > 2.0 || atodbl(arg) < -2.0)
		exit(EXIT_FAILURE);
	return (1);
}

double	atodbl(char *str)
{
	long	integer_part;
	double	frac_part;
	double	pow;
	int		sign;

	integer_part = 0;
	frac_part = 0;
	sign = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str && *str != '.')
		integer_part = (integer_part * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		frac_part += (*str++ - '0') * pow;
	}
	return ((integer_part + frac_part) * sign);
}
