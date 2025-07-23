/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:39:42 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 22:20:50 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_malloc_error(void)
{
	perror("kwa kwa kwa kwawawa...");
	exit(EXIT_FAILURE);
}

static void	init_events(t_fractal *f)
{
	mlx_hook(f->mlx_window, KeyPress, KeyPressMask, key_handle, f);
	mlx_mouse_hook(f->mlx_window, mouse_handle, f);
	mlx_hook(f->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handle, f);
	mlx_hook(f->mlx_window, MotionNotify, PointerMotionMask,
		julia_track, f);
}

void	init_default_data(t_fractal *f)
{
	init_events(f);
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->escape_value = 4;
	f->iterations = 200;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->flag = 0;
}

static void	clean_stuff(t_fractal *f)
{
	mlx_destroy_display(f->mlx_connection);
	free(f->mlx_connection);
	handle_malloc_error();
}

void	fractal_init(t_fractal *f)
{
	f->mlx_connection = mlx_init();
	if (!f->mlx_connection)
		handle_malloc_error();
	f->mlx_window = mlx_new_window(f->mlx_connection, SIZE, SIZE, f->name);
	if (!f->mlx_window)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		handle_malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_connection, SIZE, SIZE);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_connection, f->mlx_window);
		clean_stuff(f);
	}
	f->img.pixel_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bp, &f->img.line_len, &f->img.endian);
	if (f->img.pixel_ptr == NULL)
	{
		mlx_destroy_window(f->mlx_connection, f->mlx_window);
		mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
		clean_stuff(f);
	}
	init_default_data(f);
}
