/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:13:38 by fabi              #+#    #+#             */
/*   Updated: 2024/10/19 18:15:10 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# define WIDTH 500
# define HEIGHT 500

# define BLACK              0x000000
# define WHITE              0xFFFFFF
# define NEON_PINK          0xFF6EC7
# define ELECTRIC_BLUE      0x7DF9FF
# define ELECTRIC_LIME      0xCCFF00
# define VIBRANT_ORANGE     0xFF5F1F
# define ULTRA_VIOLET       0x6A0DAD
# define TURQUOISE          0x40E0D0
# define LIME_GREEN         0x32CD32
# define DEEP_SKY_BLUE      0x00BFFF
# define ORANGE_RED         0xFF4500
# define INDIGO             0x4B0082
# define VIOLET             0xEE82EE

typedef struct s_complex
{
	double	x; //real part
	double	y; //imaginary part
}	t_complex;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixel_ptr; //points to the first byte of the image data
	int		bits_per_pixel; //number of bits needed to represent a pixel color
	int		endian; //endian of the image
	int		size_line; //size of a line in bytes (line_len)
}	t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx; //mlx_connection mlx_init()
	void	*mlx_win; //mlx_new_window()
	t_img	img; //image struct
	double	escape_value; //hypotenuse
	int		iterations;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

//init.c
void		fractol_init(t_fractol *fractol);

//render.c
void		fractol_render(t_fractol *fractol);
int			track_julia(int x, int y, t_fractol *fractol);
int			ft_is_space(char c);

//utils.c
t_complex	sqr_cpx(t_complex n);
t_complex	sum_cpx(t_complex n1, t_complex n2);
int			ft_sc(const char *s1, const char *s2, size_t n);
double		ft_atodbl(const char *str);

//events.c
double		map_value(double value, t_range old_range, t_range new_range);
int			key_handler(int keysym, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);

#endif