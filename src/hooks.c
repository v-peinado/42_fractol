/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:39:12 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/04 21:02:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int keycode, t_fractol *f)
{
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY
		|| keycode == UP_KEY || keycode == DOWN_KEY)
		arrow_move(keycode, f);
	if (keycode == A_KEY || keycode == S_KEY)
		change_color(keycode, f);
	if (keycode == ESC_KEY)
		exit_when_close(keycode, f);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN)
	{
		f->zoom /= 0.8;
	}
	if (keycode == MOUSE_UP)
	{
		f->zoom *= 0.8;
	}
	if (!ft_strcmp(f->name, "julia"))
		julia(f);
	else
		check_fractal(f->name, f);
	return (0);
}

int	change_color(int keycode, t_fractol *f)
{
	if (keycode == A_KEY)
		f->color += 0x01FFFF;
	if (keycode == S_KEY)
		f->color -= 0x01FFFF;
	if (!ft_strcmp(f->name, "julia"))
		julia(f);
	else
		check_fractal(f->name, f);
	return (0);
}

int	arrow_move(int keycode, t_fractol *f)
{
	double	move;

	move = 0.05;
	if (keycode == LEFT_KEY)
		f->x -= move * f->zoom;
	if (keycode == RIGHT_KEY)
		f->x += move * f->zoom;
	if (keycode == UP_KEY)
		f->y -= move * f->zoom;
	if (keycode == DOWN_KEY)
		f->y += move * f->zoom;
	if (!ft_strcmp(f->name, "julia"))
		julia(f);
	else
		check_fractal(f->name, f);
	return (0);
}
