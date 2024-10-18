/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:51:12 by fabi              #+#    #+#             */
/*   Updated: 2024/10/18 20:02:22 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_sc(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double map_value(double value, t_range old_range, t_range new_range)
{
    if (old_range.max - old_range.min == 0)
        return new_range.min;
    return ((value - old_range.min) * (new_range.max - new_range.min)) / 
           (old_range.max - old_range.min) + new_range.min;
}



t_complex sqr_cpx(t_complex n)
{
	t_complex ret;
	
	ret.x = (n.x * n.x) - (n.y * n.y);
	ret.y = 2 * n.x * n.y;
	return (ret);
}

t_complex sum_cpx(t_complex n1, t_complex n2)
{
	t_complex ret;
	
	ret.x = n1.x + n2.x;
	ret.y = n1.y + n2.y;
	return (ret);
}

double ft_atodbl(const char *str)
{
    int sign = 1;
    double integer = 0.0, fraction = 0.0, divisor = 10.0;
    
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if (*str == '-') { sign = -1; str++; }
    else if (*str == '+') str++;
    while (*str >= '0' && *str <= '9')
        integer = integer * 10.0 + (*str++ - '0');
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9') {
            fraction += (*str++ - '0') / divisor;
            divisor *= 10.0;
        }
    }
    return sign * (integer + fraction);
}
