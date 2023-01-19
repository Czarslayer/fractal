/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:02 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/19 00:11:31 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

typedef struct l_window
{
    void	*mlx;
    void	*mlx_win;
}				t_window;

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

typedef struct s_control
{
    double move_x;
    double movesrc;
    double move_y;
    double zoom;
    double zoom_src;
    t_data *img;
    t_window *window;

    double rfix;
    double ifix;
} t_control;

typedef struct t_complexe
{
    double real;
    double imag;
} t_complexe;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int key_hook(int keycode, t_control *cont);
int mouse_hook(int button, int x, int y, t_control *cont);

void	mandelbrot(void);
void	julia(void);
void	burning_ship(void);


#endif