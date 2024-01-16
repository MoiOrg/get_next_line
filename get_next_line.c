/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:06:12 by kiparis           #+#    #+#             */
/*   Updated: 2024/01/11 15:06:12 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	size_t	i;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while ((i = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int	fd)
{
	static char	*buffer;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	return (buffer);
}