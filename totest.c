/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:09:09 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/15 23:37:28 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 200

typedef struct l_window
{
    void *mlx;
    void *mlx_win;
} t_window;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_control
{
    int move_x;
    int move_y;
    int zoom;
    t_data *img;
    t_window *window;
} t_control;

typedef struct t_complexe
{
    double real;
    double imag;
} t_complexe;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
// i need a function that will use a pixe drawing function to draw the whole window
void mandelbrot_drawer(t_control *cont, int x, int y)
{
    int iter = 0;
    t_complexe c;
    t_complexe z;
    z.imag = 0;
    z.real = 0;

    c.real = 1.1 * (x - WIDTH / 2) / (0.5 * WIDTH * cont->zoom) + (cont->move_x / WIDTH / 2);
    c.imag = (y - HEIGHT / 2) / (0.5 * HEIGHT * cont->zoom) + (cont->move_y / HEIGHT / 2);
    
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
        my_mlx_pixel_put(cont->img, x, y, 0xCCCCCC * iter);
}

int draw_cube(t_control *cont)
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
	//mlx_put_image_to_window((*img).window->mlx, (*img).window->mlx_win, img->img, 0, 0);
    return (0);
}

// now i need to make a function that will take cordinations x and y and run them trough a fractal function 
// and then return a color to draw the pixel with
int key_hook(int keycode, t_control *cont)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 123)
        cont->move_x -= cont->zoom_src / cont->zoom;
    if (keycode == 124)
        cont->move_x += 10;
    if (keycode == 125)
        cont->move_y += 10;
    if (keycode == 126)
        cont->move_y -= 10;
    if (keycode == 69)
        cont->zoom += 10;
    if (keycode == 78)
        cont->zoom -= 10;
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
    // img.control->move_y = 0;
    // img.control->zoom = 1;
    cont.zoom = 1;
    cont.window->mlx = mlx_init();
	//img.window->mlx = mlx_init();
    cont.window->mlx_win = mlx_new_window(cont.window->mlx, WIDTH, HEIGHT, "fractal baby");
	//img.window->mlx_win = mlx_new_window(img.window->mlx, WIDTH, HEIGHT, "fractal baby");
    cont.img->img = mlx_new_image(cont.window->mlx, WIDTH, HEIGHT);
	//img.img = mlx_new_image(img.window->mlx, WIDTH, HEIGHT);
    cont.img->addr = mlx_get_data_addr(cont.img->img, &cont.img->bits_per_pixel, &cont.img->line_length,
                                &cont.img->endian);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	//							&img.endian);
    mlx_key_hook(cont.window->mlx_win, key_hook, &cont);
    //mlx_key_hook(img.window->mlx_win, key_hook, &img);
    mlx_loop_hook(cont.window->mlx, draw_cube, &cont);
    //mlx_loop_hook(img.window->mlx, draw_cube, &img);
    mlx_loop(cont.window->mlx);
	//mlx_loop(img.window->mlx);
}