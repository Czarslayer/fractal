/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:02 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/15 22:24:18 by mabahani         ###   ########.fr       */
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
# define MAX_ITER 60

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
    double move_x_src;
    double move_y;
    double move_y_src;
    double zoom;
    double zoom_src;
    t_data *img;
    t_window *window;
} t_control;

typedef struct t_complexe
{
    double real;
    double imag;
} t_complexe;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif