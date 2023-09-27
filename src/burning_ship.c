/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:44:33 by vpeinado          #+#    #+#             */
/*   Updated: 2023/06/24 03:01:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_ship(t_fractol *f)
{
	double	temp;
	double	c_re;
	double	c_im;

	c_re = (f->i - X_AXIS / 2.0) * f->zoom / X_AXIS + f->x;
	c_im = (f->j - Y_AXIS / 2.0) * f->zoom / Y_AXIS + f->y;
	while (f->iter < ITERATION && f->re * f->re + f->im * f->im < 4)
	{
		temp = f->re * f->re - f->im * f->im + c_re;
		f->im = fabs(2 * f->re * f->im) + c_im;
		f->re = temp;
		f->iter++;
	}
	return (f->iter);
}

void	burning_ship(t_fractol *f)
{
	f->name = "burning_ship";
	f->i = 0;
	while (f->i < X_AXIS)
	{
		f->j = 0;
		while (f->j < Y_AXIS)
		{
			f->iter = 0;
			f->re = 0;
			f->im = 0;
			if (iterate_ship(f) >= ITERATION)
				my_mlx_putpixel(f, f->i, f->j, 0x000000);
			else
				my_mlx_putpixel(f, f->i, f->j, f->color \
				* iterate_ship(f));
			f->j++;
		}
		f->i++;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, f->x, f->y);
}
