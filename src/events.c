/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:17:17 by fabi              #+#    #+#             */
/*   Updated: 2024/10/18 18:54:13 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_handler(int button, int x, int y, t_fractol *fractol)
{
    (void)x;
    (void)y;
    if (button == Button5)
    {
        fractol->zoom *= 0.9;
    }
    else if (button == Button4)
    {
        fractol->zoom *= 1.1;
    }
    fractol_render(fractol);
    return (0);
}

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->offset_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->offset_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->offset_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->offset_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations += 10;
	else if (keysym == XK_minus)
		fractol->iterations -= 10;
	fractol_render(fractol);
	return (0);
}

int track_julia(int x, int y, t_fractol *fractol)
{
	if (ft_sc(fractol->name, "Julia", 5) == 0)
	{
		t_range old_range_x = {0.0, WIDTH};
		t_range old_range_y = {0.0, HEIGHT};
		t_range new_range_x = {-2.0, 2.0};
		t_range new_range_y = {2.0, -2.0};

		// Mappatura delle coordinate x e y
		fractol->julia_x = map_value(x, old_range_x, new_range_x) * fractol->zoom + fractol->offset_x;
		fractol->julia_y = map_value(y, old_range_y, new_range_y) * fractol->zoom + fractol->offset_y;
	}
	fractol_render(fractol);
	return (0);
}
