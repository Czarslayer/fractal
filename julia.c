/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:04 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/19 01:37:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

void julia_drawer(t_control *cont, int x, int y)
{
    int iter = 0;
    t_complexe c;
    t_complexe z;
    c.imag = cont->rfix;
    c.real = cont->ifix;
    z.real = (x - WIDTH / 2) / (0.5 * WIDTH * cont->zoom) + cont->move_x;
    z.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * cont->zoom) + cont->move_y;
    while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITER)
    {
        double tmp = z.real;
        z.real = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.imag * tmp + c.imag;
        iter++;
    }
    if (iter == MAX_ITER)
        my_mlx_pixel_put(cont->img, x, y, 0x000000);
    else
        my_mlx_pixel_put(cont->img, x, y,  0xff3a00 * iter);
}


int draw_julia(t_control *cont)
{
    int i;
    int j;

    i = 0;
    j = 0;
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
    mlx_put_image_to_window(cont->window->mlx, cont->window->mlx_win, cont->img->img, 0, 0);
    return (0);
}

int mouse_move(int x, int y, t_control *cont)
{
    if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
    {
        cont->rfix = (double)x / HEIGHT * 2 - 1;
        cont->ifix = (double)y / WIDTH * 2 - 1;
    }
    return (0);
}

void	julia(void)
{
	t_control	cont;

    cont.window = malloc(sizeof(t_window));
    cont.img = malloc(sizeof(t_data));
    cont.move_x = 0;
    cont.move_y = 0;
    cont.zoom = 0.5;
    cont.rfix = 0.285;
    cont.ifix = 0.01;
    cont.window->mlx = mlx_init();
    cont.window->mlx_win = mlx_new_window(cont.window->mlx, WIDTH, HEIGHT, "fractal baby");
    cont.img->img = mlx_new_image(cont.window->mlx, WIDTH, HEIGHT);
    cont.img->addr = mlx_get_data_addr(cont.img->img, &cont.img->bits_per_pixel, &cont.img->line_length,
                                &cont.img->endian);
    mlx_key_hook(cont.window->mlx_win, key_hook, &cont);
    mlx_mouse_hook(cont.window->mlx_win, mouse_hook, &cont);
    mlx_hook(cont.window->mlx_win, 6, 1L << 2, mouse_move, &cont);
    mlx_loop_hook(cont.window->mlx, draw_julia, &cont);
    mlx_loop(cont.window->mlx);
}