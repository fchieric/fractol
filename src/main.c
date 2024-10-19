/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:07:07 by fabi              #+#    #+#             */
/*   Updated: 2024/10/19 18:14:43 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 4 && !ft_sc(argv[1], "Julia", 6))
	{
		fractol.name = argv[1];
		fractol.julia_x = ft_atodbl(argv[2]);
		fractol.julia_y = ft_atodbl(argv[3]);
	}
	else if (argc == 2 && !ft_sc(argv[1], "Mandelbrot", 10))
	{
		fractol.name = argv[1];
	}
	else
	{
		write(2, "Usage: ./fractol Mandelbrot || Julia real imaginary\n", 52);
		exit(1);
	}
	fractol_init(&fractol);
	fractol_render(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
