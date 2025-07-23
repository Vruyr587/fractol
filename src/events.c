/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:16:33 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 19:16:35 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractal *f)
{
	mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	mlx_destroy_window(f->mlx_connection, f->mlx_window);
	mlx_destroy_display(f->mlx_connection);
	free(f->mlx_connection);
	exit(EXIT_SUCCESS);
}

static void	apply_mouse_zoom(t_fractal *f, int btn, int x, int y)
{
	double	mouse_x;
	double	mouse_y;
	double	factor;
	double	new_h;
	double	new_w;

	if (btn == SCROLL_UP)
		factor = 0.9;
	else if (btn == SCROLL_DOWN)
		factor = 1.1;
	else
		return ;
	mouse_x = f->min_re + ((double)x / SIZE) * (f->max_re - f->min_re);
	mouse_y = f->min_im + ((double)y / SIZE) * (f->max_im - f->min_im);
	new_w = (f->max_re - f->min_re) * factor;
	new_h = (f->max_im - f->min_im) * factor;
	f->min_re = mouse_x - ((mouse_x - f->min_re) * factor);
	f->max_re = f->min_re + new_w;
	f->min_im = mouse_y - ((mouse_y - f->min_im) * factor);
	f->max_im = f->min_im + new_h;
}

int	mouse_handle(int button, int x, int y, t_fractal *f)
{
	if (button == Button4 || button == Button5)
		apply_mouse_zoom(f, button, x, y);
	fractal_render(f);
	return (0);
}

int	julia_track(int x, int y, t_fractal *f)
{
	if (!ft_strcmp(f->name, "julia") && !f->flag)
	{
		f->julia_x = f->min_re + ((double)x / SIZE)
			* (f->max_re - f->min_re);
		f->julia_y = f->min_im + ((double)y / SIZE)
			* (f->max_im - f->min_im);
		fractal_render(f);
	}
	return (0);
}
