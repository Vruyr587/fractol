/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <vrasatry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:19:30 by vrasatry          #+#    #+#             */
/*   Updated: 2025/07/02 20:29:37 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 1000

# define ZOOM_IN1 61
# define ZOOM_OUT1 45
# define ZOOM_IN2 65451
# define ZOOM_OUT2 65453

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		endian;
	int		bp;
	int		line_len;
}	t_image;

typedef struct s_fractal
{
	t_image	img;
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	int		iterations;
	int		color_shift;
	int		flag;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	escape_value;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		zoom_view(int key, t_fractal *f);
void		move_view(int key, t_fractal *f);
int			key_handle(int key, t_fractal *f);
int			close_handle(t_fractal *f);
int			mouse_handle(int button, int x, int y, t_fractal *f);
int			julia_track(int x, int y, t_fractal *f);
void		init_default_data(t_fractal *f);
void		refresh_image(t_fractal *f);
void		fractal_init(t_fractal *f);
void		check_zeros(char *arg);
void		pixel_handling(int x, int y, t_fractal *f);
void		pixel_put(int px, int py, t_image *img, int color);
void		define_fractal_type(t_complex *z, t_complex *c, t_fractal *f);
int			get_color(int i, int max_iter, int shift);
void		fractal_render(t_fractal *f);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex z);
int			ft_strcmp(char *s1, char *s2);
int			check_julia_input(char *arg);
double		atodbl(char *str);

#endif