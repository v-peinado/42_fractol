/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:48:23 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/13 19:40:49 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_fractol *f)
{
	mlx_mouse_hook(f->win_ptr, zoom, f);
	mlx_key_hook(f->win_ptr, key_hooks, f);
	mlx_hook(f->win_ptr, 17, 0, exit_when_close, f);
}

void	make_image(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx_ptr, X_AXIS, Y_AXIS);
	f->img_addr = mlx_get_data_addr(f->img, &f->img_bpp,
			&f->img_line_length, &f->img_endian);
}

void	make_win(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, X_AXIS, Y_AXIS, "Fract-ol 42");
}

/*void leaks_ft()
{
	system("leaks fractol");
}	atexit(leaks_ft);*/

int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc == 2 || argc == 4)
	{
		if (!arg_check(argv[1], argv[2], argv[3]))
			input_help();
		f = ft_calloc(1, sizeof(t_fractol));
		if (!f)
			exit(EXIT_FAILURE);
		f->color = COLOR;
		f->zoom = 4.0;
		make_win(f);
		make_image(f);
		if (argc == 2)
			check_fractal(argv[1], f);
		else
			julia_check(argv[1], argv[2], argv[3], f);
		hooks(f);
		mlx_loop(f->mlx_ptr);
	}
	else
		input_help();
	return (0);
}
