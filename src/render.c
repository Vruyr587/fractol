/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:12:27 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 19:12:30 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int px, int py, t_image *img, int color)
{
	int	offset;

	offset = ((py * img->line_len) + (px * img->bp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	define_fractal_type(t_complex *z, t_complex *c, t_fractal *f)
{
	if (!ft_strcmp(f->name, "julia"))
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	get_color(int i, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i >= max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + shift) % 256;
	g = (g + shift) % 256;
	b = (b + shift) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	fractal_render(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	refresh_image(f);
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			pixel_handling(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_connection, f->mlx_window,
		f->img.img_ptr, 0, 0);
}
