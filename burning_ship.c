/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:04 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/19 00:21:54 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

void burningship_drawer(t_control *cont, int x, int y)
{
    int iter = 0;
    t_complexe c;
    t_complexe z;
    z.imag = 0;
    z.real = 0;
    c.real = (x - WIDTH / 2) / (0.5 * WIDTH * cont->zoom) + cont->move_x;
    c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * cont->zoom) + cont->move_y;
    while (z.real * z.real + z.imag * z.imag < 4 && iter < MAX_ITER)
    {
        double tmp = z.real;
        z.real = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = fabs(2 * z.imag * tmp) + c.imag;
        iter++;
    }
    if (iter == MAX_ITER)
        my_mlx_pixel_put(cont->img, x, y, 0x000000);
    else
        my_mlx_pixel_put(cont->img, x, y, 0xff3a00 * iter);
}


int draw_burningship(t_control *cont)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < WIDTH)
    {
        while (j < HEIGHT)
        {
            burningship_drawer(cont, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(cont->window->mlx, cont->window->mlx_win, cont->img->img, 0, 0);
    return (0);
}

void	burning_ship(void)
{

	t_control	cont;

    cont.window = malloc(sizeof(t_window));
    cont.img = malloc(sizeof(t_data));
    cont.move_x = 0;
    cont.move_y = 0;
    cont.zoom = 0.5;
    cont.window->mlx = mlx_init();
    cont.window->mlx_win = mlx_new_window(cont.window->mlx, WIDTH, HEIGHT, "fractal baby");
    cont.img->img = mlx_new_image(cont.window->mlx, WIDTH, HEIGHT);
    cont.img->addr = mlx_get_data_addr(cont.img->img, &cont.img->bits_per_pixel, &cont.img->line_length,
                                &cont.img->endian);
    mlx_key_hook(cont.window->mlx_win, key_hook, &cont);
    mlx_mouse_hook(cont.window->mlx_win, mouse_hook, &cont);
    mlx_loop_hook(cont.window->mlx, draw_burningship, &cont);
    mlx_loop(cont.window->mlx);
}