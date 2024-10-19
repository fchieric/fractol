/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:17:17 by fabi              #+#    #+#             */
/*   Updated: 2024/10/19 17:58:31 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_value(double value, t_range old_range, t_range new_range)
{
	if (old_range.max - old_range.min == 0)
		return (new_range.min);
	return (((value - old_range.min) * (new_range.max - new_range.min))
		/ (old_range.max - old_range.min) + new_range.min);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractol->zoom *= 1.1;
	else if (button == Button4)
		fractol->zoom *= 0.9;
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
		fractol->offset_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->offset_y += (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations += 10;
	else if (keysym == XK_minus)
		fractol->iterations -= 10;
	fractol_render(fractol);
	return (0);
}

int	track_julia(int x, int y, t_fractol *fractol)
{
	t_range	old_range_x;
	t_range	old_range_y;	
	t_range	new_range_x;
	t_range	new_range_y;

	if (fractol->name != NULL && ft_sc(fractol->name, "Julia", 5) == 0)
	{
		old_range_x.min = 0.0;
		old_range_x.max = (double)WIDTH;
		old_range_y.min = 0.0;
		old_range_y.max = (double)HEIGHT;
		new_range_x.min = -2.0;
		new_range_x.max = 2.0;
		new_range_y.min = 2.0;
		new_range_y.max = -2.0;
		fractol->julia_x = map_value(x, old_range_x, new_range_x)
			* fractol->zoom + fractol->offset_x;
		fractol->julia_y = map_value(y, old_range_y, new_range_y)
			* fractol->zoom + fractol->offset_y;
	}
	fractol_render(fractol);
	return (0);
}
