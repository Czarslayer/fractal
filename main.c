/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:02:32 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/23 21:57:14 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_error(int f)
{
	if (f == 1)
	{
		ft_putstr_fd("\e[1;31mERROR: invalid fractal name\e[0m\n", 2);
		ft_putstr_fd("\e[4;33mfractal: mandelbrot, julia, burningship\e[0m\n", 2);
	}
	else if (f == 0)
	{
		ft_putstr_fd("\e[1;31mERROR: invalid number of arguments\e[0m\n", 2);
		ft_putstr_fd("\e[4;33mfractal:\e[0m\
		\e[0;33m./fractal mandelbrot, julia, burningship\e[0m\n", 2);
		ft_putstr_fd("\e[4;33mjulia params:\e[0m\
		\e[0;33m./fractal julia 'real' 'imag'\e[0m\n", 2);
	}
	exit(0);
}

void	handle_fractal_1(t_control *cont, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		mandelbrot(*cont);
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		cont->rfix = -0.4;
		cont->ifix = 0.6;
		julia(*cont);
	}
	else if (ft_strncmp(av[1], "burningship", 12) == 0)
		burning_ship(*cont);
	else
		print_error(1);
}

void	handle_fractal_2(t_control *cont, char **av)
{
	if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		cont->rfix = atod(av[2]);
		cont->ifix = atod(av[3]);
		julia(*cont);
	}
	else
		print_error(1);
}

void	error_checker(int ac, char **av)
{
	if (ac == 2)
		handle_error_1(av);
	else if (ac == 4)
		handle_error_2(av);
	else
		print_error(0);
}

int	main(int ac, char **av)
{
	t_control	cont;

	error_checker(ac, av);
	cont.window = malloc(sizeof(t_window));
	cont.img = malloc(sizeof(t_data));
	cont.window->mlx = mlx_init();
	cont.window->mlx_win = mlx_new_window(cont.window->mlx, \
										WIDTH, HEIGHT, "Fractal Visualizer");
	cont.img->img = mlx_new_image(cont.window->mlx, WIDTH, HEIGHT);
	cont.img->addr = mlx_get_data_addr(cont.img->img, \
					&cont.img->bits_per_pixel, &cont.img->line_length, \
					&cont.img->endian);
	cont.move_x = 0;
	cont.move_y = 0;
	cont.zoom = 0.5;
	cont.color = 256 * 256 * 265;
	if (ac == 2)
		handle_fractal_1(&cont, av);
	else if (ac == 4)
		handle_fractal_2(&cont, av);
	else
		print_error(0);
	return (0);
}
