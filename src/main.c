/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:22:27 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 22:21:08 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_image(t_fractal *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	f->img.img_ptr = mlx_new_image(f->mlx_connection, SIZE, SIZE);
	f->img.pixel_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bp, &f->img.line_len, &f->img.endian);
}

void	check_zeros(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '0' && !ft_strchr(arg, '.'))
		exit(EXIT_FAILURE);
	if (arg[i] == '0' && arg[i + 1] == '0' && ft_strchr(arg, '.'))
		exit(EXIT_FAILURE);
}

static void	parse_julia_args(char **argv, t_fractal *f)
{
	if (check_julia_input(argv[2]))
		f->julia_x = atodbl(argv[2]);
	if (check_julia_input(argv[3]))
		f->julia_y = atodbl(argv[3]);
}

static void	print_usage(void)
{
	write(1,
		"Usage:\n\t./fractol mandelbrot\n\t./fractol burningship\n\t"
		"./fractol julia <real> <imaginary>\n", 96);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
				|| !ft_strcmp(argv[1], "burningship")))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
			parse_julia_args(argv, &fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		print_usage();
	return (0);
}
