/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:19:28 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 19:19:30 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handle(int key, t_fractal *f)
{
	if (key == XK_Escape)
		close_handle(f);
	else if (key == XK_Left || key == XK_Right
		|| key == XK_Up || key == XK_Down)
		move_view(key, f);
	else if (key == ZOOM_IN1 || key == ZOOM_IN2
		|| key == ZOOM_OUT1 || key == ZOOM_OUT2)
		zoom_view(key, f);
	else if (key == XK_m)
		f->color_shift += 5;
	else if (key == XK_l)
		f->flag = !f->flag;
	fractal_render(f);
	return (0);
}

void	move_view(int key, t_fractal *f)
{
	double	delta_re;
	double	delta_im;

	delta_re = 0.1 * (f->max_re - f->min_re);
	delta_im = 0.1 * (f->max_im - f->min_im);
	if (key == XK_Left)
	{
		f->min_re -= delta_re;
		f->max_re -= delta_re;
	}
	else if (key == XK_Right)
	{
		f->min_re += delta_re;
		f->max_re += delta_re;
	}
	else if (key == XK_Up)
	{
		f->min_im -= delta_im;
		f->max_im -= delta_im;
	}
	else if (key == XK_Down)
	{
		f->min_im += delta_im;
		f->max_im += delta_im;
	}
}

void	zoom_view(int key, t_fractal *f)
{
	double	factor;

	factor = 1.1;
	if (key == ZOOM_IN1 || key == ZOOM_IN2)
	{
		f->min_re += (f->max_re - f->min_re) * (1 - 1 / factor);
		f->max_re -= (f->max_re - f->min_re) * (1 - 1 / factor);
		f->min_im += (f->max_im - f->min_im) * (1 - 1 / factor);
		f->max_im -= (f->max_im - f->min_im) * (1 - 1 / factor);
	}
	else if (key == ZOOM_OUT1 || key == ZOOM_OUT2)
	{
		f->min_re -= (f->max_re - f->min_re) * (factor - 1);
		f->max_re += (f->max_re - f->min_re) * (factor - 1);
		f->min_im -= (f->max_im - f->min_im) * (factor - 1);
		f->max_im += (f->max_im - f->min_im) * (factor - 1);
	}
}
