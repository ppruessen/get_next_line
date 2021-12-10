/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:30:57 by pprussen          #+#    #+#             */
/*   Updated: 2021/11/11 14:40:53 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*check_and_fill(int fd, char *left_over)
{
	ssize_t	char_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	char_read = 1;
	while (!(ft_strchr(left_over, '\n')) && char_read != 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		left_over = ft_strjoin(left_over, buffer);
	}
	free(buffer);
	return (left_over);
}

char	*extract_line(char *left_over)
{
	char	*result;
	int		i;

	if (left_over[0] == '\0')
		return (NULL);
	i = 0;
	while (left_over[i] != '\n' && left_over[i] != '\0')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (left_over[i] != '\n' && left_over[i] != '\0')
	{
		result[i] = left_over[i];
		i++;
	}
	if (left_over[i] == '\n')
	{
		result[i] = '\n';
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*extract_rest(char *left_over)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (left_over[i] != '\n' && left_over[i] != '\0')
		i++;
	if (!left_over[i])
	{
		free(left_over);
		return (NULL);
	}
	rest = malloc(ft_strlen(left_over) - i + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (left_over[i])
		rest[j++] = left_over[i++];
	rest[j] = '\0';
	free(left_over);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*left_over[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_over[fd] = check_and_fill(fd, left_over[fd]);
	if (!left_over[fd])
		return (NULL);
	result = extract_line(left_over[fd]);
	left_over[fd] = extract_rest(left_over[fd]);
	return (result);
}
