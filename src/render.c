/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:29:24 by fabi              #+#    #+#             */
/*   Updated: 2024/10/19 17:46:58 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pxl_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_sc(fractol->name, "Mandelbrot", 10) == 0)
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0;
		z->y = 0;
	}
	else if ((ft_sc(fractol->name, "Julia", 5) == 0))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
}

static void	handle_pxl(t_fractol *fractol, int x, int y, int i)
{
	t_complex	c;
	t_complex	z;
	int			color;

	z.x = (x - WIDTH / 2.0) / (0.25 * WIDTH * fractol->zoom)
		+ fractol->offset_x;
	z.y = (y - HEIGHT / 2.0) / (0.25 * HEIGHT * fractol->zoom)
		+ fractol->offset_y;
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		z = sum_cpx(sqr_cpx(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map_value(i, (t_range){0, fractol->iterations},
					(t_range){BLACK, WHITE});
			my_pxl_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	color = map_value(i, (t_range){0, fractol->iterations},
			(t_range){BLACK, WHITE});
	my_pxl_put(x, y, &fractol->img, BLACK);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pxl(fractol, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
}
