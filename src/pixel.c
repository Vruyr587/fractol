/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:14:29 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 19:14:38 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	map_to_complex_plane(int px, int py, t_fractal *f)
{
	t_complex	z;

	z.x = f->min_re + ((double)px / SIZE) * (f->max_re - f->min_re);
	z.y = f->min_im + ((double)py / SIZE) * (f->max_im - f->min_im);
	return (z);
}

static int	calculate_color(t_complex z, t_complex c, t_fractal *f)
{
	int		iter;

	iter = 0;
	while (iter++ < f->iterations)
	{
		if (!ft_strcmp(f->name, "burningship"))
		{
			z.x = fabs(z.x);
			z.y = fabs(z.y);
		}
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x + z.y * z.y) > f->escape_value)
			return (get_color(iter, f->iterations, f->color_shift));
	}
	return (0x000000);
}

void	pixel_handling(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			color;

	z = map_to_complex_plane(x, y, f);
	define_fractal_type(&z, &c, f);
	color = calculate_color(z, c, f);
	pixel_put(x, y, &f->img, color);
}
