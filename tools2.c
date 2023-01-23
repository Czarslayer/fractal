/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:17:45 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/23 15:57:45 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

double	get_int(char *str, int *i)
{
	double	res;

	res = 0;
	while (ft_isdigit(str[*i]))
	{
		res = res * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	return (res);
}

double	get_dec(char *str, int *i)
{
	double	dec;
	int		dec_count;

	dec = 0;
	dec_count = 0;
	while (ft_isdigit(str[*i]))
	{
		dec = dec * 10 + (str[*i] - '0');
		*i = *i + 1;
		dec_count++;
	}
	while (dec_count--)
		dec /= 10;
	return (dec);
}

double	atod(char *str)
{
	int		i;
	int		sign;
	double	res;
	double	dec;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = get_int(str, &i);
	if (str[i] == '.')
	{
		i++;
		dec = get_dec(str, &i);
		return ((res + dec) * sign);
	}
	return (res * sign);
}
