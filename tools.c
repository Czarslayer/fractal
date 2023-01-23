/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:44:22 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/23 19:54:33 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_control *cont)
{
	cont->movesrc = 0.1 / (cont->zoom);
	if (keycode == 53)
		exit(0);
	if (keycode == 38)
		cont->color = 265 * 256 * 256;
	if (keycode == 40)
		cont->color = 0xff3a00;
	if (keycode == 37)
		cont->color = 0x7CFC00;
	if (keycode == 4)
		cont->color = 256;
	if (keycode == 123)
		cont->move_x -= cont->movesrc;
	if (keycode == 124)
		cont->move_x += cont->movesrc;
	if (keycode == 125)
		cont->move_y += cont->movesrc;
	if (keycode == 126)
		cont->move_y -= cont->movesrc;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_control *cont)
{
	(void)x;
	(void)y;
	cont->zoom_src = (cont->zoom / 10);
	if (button == 4)
		cont->zoom += cont->zoom_src;
	if (button == 5)
		cont->zoom -= cont->zoom_src;
	if (button == 3)
	{
		cont->zoom = 0.5;
		cont->move_x = 0;
		cont->move_y = 0;
	}
	return (0);
}

int	close_window(t_control *cont)
{
	(void)cont;
	exit(0);
	return (0);
}
