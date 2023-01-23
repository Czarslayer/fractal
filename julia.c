/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:04 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/23 23:16:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_drawer(t_control *cont, int x, int y)
{
	t_complexe	c;
	t_complexe	z;
	int			iter;
	double		tmp;

	iter = 0;
	c.imag = cont->ifix;
	c.real = cont->rfix;
	z.real = (x - (WIDTH * 0.5)) / ((WIDTH * 0.5) * cont->zoom) + cont->move_x;
	z.imag = (y - (HEIGHT * 0.5)) / ((HEIGHT * 0.5) * cont->zoom) \
	+ cont->move_y;
	z.imag *= -1;
	while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITER)
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.imag * tmp + c.imag;
		iter++;
	}
	if (iter == MAX_ITER)
		my_mlx_pixel_put(cont->img, x, y, 0x000000);
	else
		my_mlx_pixel_put(cont->img, x, y, iter * cont->color);
}

int	draw_julia(t_control *cont)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(cont->window->mlx, cont->window->mlx_win);
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			julia_drawer(cont, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(cont->window->mlx, \
						cont->window->mlx_win, cont->img->img, 0, 0);
	return (0);
}

int	mouse_move(int x, int y, t_control *cont)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		cont->rfix = (double)x / HEIGHT * 2 - 1;
		cont->ifix = (double)y / WIDTH * 2 - 1;
	}
	return (0);
}

void	julia(t_control	cont)
{
	mlx_hook(cont.window->mlx_win, 2, 0, key_hook, &cont);
	mlx_mouse_hook(cont.window->mlx_win, mouse_hook, &cont);
	mlx_hook(cont.window->mlx_win, 6, 0, mouse_move, &cont);
	mlx_hook(cont.window->mlx_win, 17, 0, close_window, &cont);
	mlx_loop_hook(cont.window->mlx, draw_julia, &cont);
	mlx_loop(cont.window->mlx);
}
