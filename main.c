/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:02:32 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/19 00:19:48 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "get_next_line.h"
#include "./libft/libft.h"

int main(int ac,char **av)
{
    if(ac == 2)
    {
        if(ft_strncmp(av[1], "mandelbrot", 11) == 0)
            mandelbrot();
        else if(ft_strncmp(av[1], "julia", 6) == 0)
            julia();
        else if(ft_strncmp(av[1], "burningship", 12) == 0)
            burning_ship();
        else
            write(2,"Error: invalid fractal name\n", 28);
    }
}