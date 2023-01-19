/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:31:13 by mabahani          #+#    #+#             */
/*   Updated: 2022/10/23 12:57:43 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len--)
	{
		if (s[len] == (char)c)
		{
			return ((char *)s + len);
		}
	}
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	return (0);
}
