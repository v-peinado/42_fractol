/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:32:42 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/04 21:01:55 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arg_check(char *argv_1, char *argv_2, char *argv_3)
{
	if (!ft_strcmp(argv_1, "julia") && argv_2 != NULL && argv_3 != NULL)
	{
		if (ft_strtod(argv_2) && ft_strtod(argv_3)
			&& ft_strtod(argv_2) >= -2.0 && ft_strtod(argv_2) <= 2.0
			&& ft_strtod(argv_3) >= -2.0 && ft_strtod(argv_3) <= 2.0)
			return (1);
	}
	if (!ft_strcmp(argv_1, "julia_1") || !ft_strcmp(argv_1, "julia_2")
		|| !ft_strcmp(argv_1, "julia_3") || !ft_strcmp(argv_1, "burning_ship")
		|| !ft_strcmp(argv_1, "mandelbrot"))
	{
		if (argv_2 != NULL && argv_3 != NULL)
			return (0);
		return (1);
	}
	return (0);
}

void	julia_check(char *fractal_type, char *j_r, char *j_i, t_fractol *f)
{
	f->name = fractal_type;
	f->julia_r = ft_strtod(j_r);
	f->julia_i = ft_strtod(j_i);
	julia(f);
}

void	check_fractal(char *fractal_type, t_fractol *f)
{
	if (!ft_strcmp(fractal_type, "mandelbrot"))
		mandelbrot(f);
	else if (!ft_strcmp(fractal_type, "burning_ship"))
		burning_ship(f);
	else if (!ft_strcmp(fractal_type, "julia_1")
		|| !ft_strcmp(fractal_type, "julia_2")
		|| !ft_strcmp(fractal_type, "julia_3"))
	{
		f->name = fractal_type;
		julia(f);
	}
	else
	{
		input_help();
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
}
