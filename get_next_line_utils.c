/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:31:06 by pprussen          #+#    #+#             */
/*   Updated: 2021/11/10 10:57:05 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *left_over, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_over)
	{
		left_over = (char *)malloc(1 * sizeof(char));
		left_over[0] = '\0';
	}
	if (!left_over || !buffer)
		return (NULL);
	str = malloc(ft_strlen(left_over) + ft_strlen(buffer) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_over)
		while (left_over[++i] != '\0')
			str[i] = left_over[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(left_over) + ft_strlen(buffer)] = '\0';
	free(left_over);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (0);
}
