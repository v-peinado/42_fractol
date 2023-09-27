/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:12:28 by vpeinado          #+#    #+#             */
/*   Updated: 2023/06/25 01:00:24 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_help(void)
{
	printf(" _______________________________\n");
	printf("|                               |\n");
	printf("| Use: ./fractol [fractal_name] |\n");
	printf("|_______________________________|\n");
	printf("|      Available fractals:      |\n");
	printf("|                               |\n");
	printf("|        [mandelbrot]           |\n");
	printf("|        [julia_1]              |\n");
	printf("|        [julia_2]              |\n");
	printf("|        [julia_3]              |\n");
	printf("|        [burning_ship]         |\n");
	printf("|        *[julia]               |\n");
	printf("|_______________________________|\n\n");
	printf(" *If you choose [julia]\n");
	printf(" Enter the real and imaginary parts between -2 and 2\n");
	printf(" Example:    ./fractol julia -0.2321 -0.835\n\n");
	exit(EXIT_FAILURE);
}
