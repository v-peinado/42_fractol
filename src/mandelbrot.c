/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:05:03 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/05 11:35:51 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(t_fractol *f)
{
	double	temp;
	double	c_re;
	double	c_im;

	c_re = (f->i - X_AXIS / 2.0) * f->zoom / X_AXIS + f->x;
	c_im = (f->j - Y_AXIS / 2.0) * f->zoom / Y_AXIS + f->y;
	while (f->iter < ITERATION && f->re * f->re + f->im * f->im < 4)
	{
		temp = pow(f->re, 2) - pow(f->im, 2) + c_re;
		f->im = 2 * f->re * f->im + c_im;
		f->re = temp;
		f->iter++;
	}
	return (f->iter);
}

void	mandelbrot(t_fractol *f)
{
	f->name = "mandelbrot";
	f->i = 0;
	while (f->i < X_AXIS)
	{
		f->j = 0;
		while (f->j < Y_AXIS)
		{
			f->iter = 0;
			f->re = 0;
			f->im = 0;
			if (iterate_mandelbrot(f) >= ITERATION)
				my_mlx_putpixel(f, f->i, f->j, 0x000000);
			else
				my_mlx_putpixel(f, f->i, f->j, f->color \
				* iterate_mandelbrot(f));
			f->j++;
		}
		f->i++;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, f->x, f->y);
}
