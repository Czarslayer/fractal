/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:15:04 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/23 21:34:59 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	handle_error_1(char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		return (0);
	else if (ft_strncmp(av[1], "julia", 6) == 0)
		return (0);
	else if (ft_strncmp(av[1], "burningship", 12) == 0)
		return (0);
	else
		print_error(1);
	return (1);
}

int	handle_error_2(char **av)
{
	if (ft_strncmp(av[1], "julia", 6) == 0)
		return (0);
	else
		print_error(1);
	return (1);
}
