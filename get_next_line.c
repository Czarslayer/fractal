/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:12:03 by mabahani          #+#    #+#             */
/*   Updated: 2022/11/25 18:20:09 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_af_newline(char *temp)
{
	size_t	i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!temp)
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (!temp[i] || !temp[i + 1])
		return (free(temp), NULL);
	line = (char *)malloc((ft_strlen(temp) - i));
	if (!line)
		return (NULL);
	i++;
	while (temp[i] != '\0')
		line[j++] = temp[i++];
	line[j] = '\0';
	free(temp);
	return (line);
}

char	*line_bf_newline(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*line_reader(int fd, char *temp)
{
	int		a;
	char	*p;

	a = 1;
	p = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (0);
	while (!finder(temp, '\n'))
	{
		a = read(fd, p, BUFFER_SIZE);
		if (a == 0)
			return (free(p), temp);
		if (a == -1)
			return (free(p), free(temp), NULL);
		p[a] = '\0';
		temp = ft_strjoin(temp, p);
	}
	free(p);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	backup = line_reader(fd, backup);
	if (backup == NULL)
	{
		return (NULL);
	}
	line = line_bf_newline(backup);
	backup = line_af_newline(backup);
	return (line);
}
