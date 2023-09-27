/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:43:20 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/04 18:56:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia_values(double *c_re, double *c_im, t_fractol *f)
{
	if (!ft_strcmp(f->name, "julia_1"))
	{
		*c_re = -0.2321;
		*c_im = -0.835;
	}
	if (!ft_strcmp(f->name, "julia_2"))
	{
		*c_re = -0.3842;
		*c_im = -0.70176;
	}
	if (!ft_strcmp(f->name, "julia_3"))
	{
		*c_re = 0.01;
		*c_im = 0.285;
	}
	if (!ft_strcmp(f->name, "julia"))
	{
		*c_re = f->julia_r;
		*c_im = f->julia_i;
	}
}

int	iterate_julia(t_fractol *f)
{
	double	temp;
	double	c_re;
	double	c_im;

	set_julia_values(&c_re, &c_im, f);
	while (f->iter < ITERATION && f->re * f->re + f->im * f->im < 4)
	{
		temp = f->re * f->re - f->im * f->im;
		f->im = 2 * f->re * f->im + c_re;
		f->re = temp + c_im;
		f->iter++;
	}
	return (f->iter++);
}

void	julia(t_fractol *f)
{
	f->i = 0;
	while (f->i < X_AXIS)
	{
		f->j = 0;
		while (f->j < Y_AXIS)
		{
			f->iter = 0;
			f->re = (f->i - X_AXIS / 2) * (f->zoom / X_AXIS) + f->x;
			f->im = (f->j - Y_AXIS / 2) * (f->zoom / Y_AXIS) + f->y;
			if (iterate_julia(f) >= ITERATION)
				my_mlx_putpixel(f, f->i, f->j, 0x000000);
			else
				my_mlx_putpixel(f, f->i, f->j, f->color \
				* iterate_julia(f));
			f->j++;
		}
		f->i++;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, f->x, f->y);
}
