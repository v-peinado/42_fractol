/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:30:46 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/04 21:07:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_strtod(char *s)
{
	double	nbr;
	int		negative;
	int		i;

	nbr = 0.0;
	negative = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10.0 + (s[i] - '0');
		i++;
	}
	return (ft_strtod_helper(s, nbr, negative, i));
}

double	ft_strtod_helper(char *s, double nbr, int negative, int i)
{
	double	divisor;

	if (s[i] == '.')
	{
		divisor = 10.0;
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			nbr = nbr + (s[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
		if ((s[i] >= 'a' && s[i] <= 'z')
			|| (s[i] >= 'A' && s[i] <= 'Z')
			|| s[i] == '.')
			return (0.0);
	}
	if (negative)
		nbr = -nbr;
	return (nbr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	my_mlx_putpixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img_addr + (y * f->img_line_length + x * (f->img_bpp / 8));
	*(unsigned int *)dst = color;
}

int	exit_when_close(int keycode, t_fractol *f)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(f->mlx_ptr, f->img);
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		free(f);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
