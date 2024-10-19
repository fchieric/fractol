/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:47:58 by fabi              #+#    #+#             */
/*   Updated: 2024/10/19 17:43:02 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Failed malloc");
	exit(1);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 100;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->zoom = 1.0;
}

static void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, KeyPress, KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->mlx_win, DestroyNotify, StructureNotifyMask,
		close_handler, fractol);
	mlx_hook(fractol->mlx_win, ButtonPress, ButtonPressMask,
		mouse_handler, fractol);
	mlx_hook(fractol->mlx_win, MotionNotify, PointerMotionMask,
		track_julia, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		malloc_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_win == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel, &fractol->img.size_line,
			&fractol->img.endian);
	event_init(fractol);
	data_init(fractol);
}
