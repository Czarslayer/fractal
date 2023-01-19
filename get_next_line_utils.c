/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:12:16 by mabahani          #+#    #+#             */
/*   Updated: 2022/11/25 18:12:16 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	finder(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (i < len && s1[i] != '\n')
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	i = 0;
	j = 0;
	ptr = malloc((len1 + len2 + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (s1[i] != '\0')
			ptr[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			ptr[j++] = s2[i++];
		ptr[j] = '\0';
	}
	free(s1);
	return (ptr);
}
