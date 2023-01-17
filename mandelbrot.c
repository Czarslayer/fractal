/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:04:04 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/16 23:20:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void mandelbrot_drawer(t_control *cont, int x, int y)
{
    int iter = 0;
    t_complexe c;
    t_complexe z;
    z.imag = 0;
    z.real = 0;

    // c.real = 1.1 * (x - WIDTH / 2) / (0.5 * WIDTH * cont->zoom) + (cont->move_x / WIDTH / 2);
    // c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * cont->zoom) + (cont->move_y / HEIGHT / 2);
    c.real = (x - WIDTH / 2) / (0.5 * WIDTH * cont->zoom) + cont->move_x;
    c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * cont->zoom) + cont->move_y;
    //printf("cont->move_x = %d\n", cont->move_x);
    
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
        my_mlx_pixel_put(cont->img, x, y, 265 * iter);
}


int draw(t_control *cont)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < WIDTH)
    {
        while (j < HEIGHT)
        {
            mandelbrot_drawer(cont, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(cont->window->mlx, cont->window->mlx_win, cont->img->img, 0, 0);
    return (0);
}

int key_hook(int keycode, t_control *cont)
{
    cont->movesrc = 0.1 / (cont->zoom);
    if (keycode == 53)
        exit(0);
    if (keycode == 123)
        cont->move_x -= cont->movesrc;
    if (keycode == 124)
        cont->move_x += cont->movesrc;
    if (keycode == 125)
        cont->move_y += cont->movesrc;
    if (keycode == 126)
        cont->move_y -= cont->movesrc;
        printf("cont->move_x = %f: cont->move_y = %f: cont->zoom %f\n", cont->move_x, cont->move_y, cont->zoom_src);
    return (0);
}

int mouse_hook(int button, int x, int y, t_control *cont)
{
    cont->zoom_src = 2 * (cont->zoom / 10);
    if (button == 4)
        cont->zoom += cont->zoom_src;
    if (button == 5)
        cont->zoom -= cont->zoom_src;
    if(button == 3)
        cont->zoom = 1;
    return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_control	cont;

    cont.window = malloc(sizeof(t_window));
    cont.img = malloc(sizeof(t_data));
    cont.move_x = 0;
    cont.move_y = 0;
    cont.zoom = 1;
   // cont.zoom_src = 2 * (cont.zoom / 10);
    cont.window->mlx = mlx_init();
    cont.window->mlx_win = mlx_new_window(cont.window->mlx, WIDTH, HEIGHT, "fractal baby");
    cont.img->img = mlx_new_image(cont.window->mlx, WIDTH, HEIGHT);
    cont.img->addr = mlx_get_data_addr(cont.img->img, &cont.img->bits_per_pixel, &cont.img->line_length,
                                &cont.img->endian);
    mlx_key_hook(cont.window->mlx_win, key_hook, &cont);
    mlx_mouse_hook(cont.window->mlx_win, mouse_hook, &cont);
    mlx_loop_hook(cont.window->mlx, draw, &cont);
    mlx_loop(cont.window->mlx);
}