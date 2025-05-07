/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:08:33 by vpeinado          #+#    #+#             */
/*   Updated: 2025/05/07 11:18:07 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define X_AXIS 600
# define Y_AXIS 600
# define COLOR 0xFFEAFF
# define ITERATION 70//details in fractals setss

/* Keys */

# define LEFT_KEY 65361    
# define RIGHT_KEY 65363   
# define DOWN_KEY 65364    
# define UP_KEY 65362      
# define ESC_KEY 65307     
# define MOUSE_UP 4        
# define MOUSE_DOWN 5      
# define A_KEY 97          
# define S_KEY 115         

# include <stdio.h>
# include <math.h> 
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	double		x;
	double		y;
	int			i;
	int			j;
	double		julia_r;
	double		julia_i;
	double		re;
	double		im;
	int			color;
	int			iter;
	double		zoom;
	void		*img;
	char		*img_addr;
	int			img_bpp;
	int			img_line_length;
	int			img_endian;
}	t_fractol;

/* Libft functions */

void		ft_bzero(void *str, size_t n);
double		ft_strtod(char *s);
double		ft_strtod_helper(char *s, double nbr, int negative, int i);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t nitems, size_t size);

/* Fractals */

void		mandelbrot(t_fractol *f);
int			iterate_mandelbrot(t_fractol *f);
void		burning_ship(t_fractol *f);
int			iterate_ship(t_fractol *f);
void		julia(t_fractol *f);
int			iterate_julia(t_fractol *f);
void		set_julia_values(double *c_re, double *c_im, t_fractol *f);

/* Hooks */

int			change_color(int keycode, t_fractol *f);
int			key_hooks(int keycode, t_fractol *f);
int			zoom(int keycode, int x, int y, t_fractol *f);
int			arrow_move(int keycode, t_fractol *f);

/* Checkers, utils and help */

void		check_fractal(char *fractal_type, t_fractol *f);
void		input_help(void);
void		my_mlx_putpixel(t_fractol *f, int x, int y, int color);
void		julia_check(char *fractal_type, char *j_r, char *j_i, t_fractol *f);
int			arg_check(char *argv_1, char *argv_2, char *argv_3);
int			exit_when_close(int keycode, t_fractol *f);

#endif