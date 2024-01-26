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

char	*join_free(char *stack, char *buffer)
{
	char	*temp;

	if (!stack)
		return (buffer);
	temp = ft_strjoin(stack, buffer);
	free(stack);
	return (temp);
}

char	*stack_rest(char *stack)
{
	char	*rest;
	size_t	len;
	size_t	j;

	len = 0;
	while (stack[len] && stack[len] != '\n')
		len++;
	if (!stack[len])
		return (free(stack), NULL);
	rest = ft_calloc((ft_strlen(stack) - len + 1), sizeof(char));
	if (!rest)
		return (free(stack), NULL);
	j = 0;
	len++;
	while (stack[len + j])
	{
		rest[j] = stack[len + j];
		j++;
	}
	free(stack);
	return (rest);
}

char	*stack_clean(char *stack)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while ((stack[i] != '\n') && stack[i])
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] && stack[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *stack)
{
	char		*buffer;
	ssize_t		count;

	if (!stack)
		stack = ft_calloc(1, 1);
	if (!stack)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(stack), NULL);
	while(((count = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[count] = 0;
		stack = join_free(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if ((count == 0 && ft_strlen(stack) == 0) || count < 0)
		return (free(stack),free(buffer), NULL);
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
 		return (NULL);
	stack = read_file(fd, stack);
	if (!stack)
		return (NULL);
	line = stack_clean(stack);
	if (!line)
		return (NULL);
	stack = stack_rest(stack);
	if (!stack)
		return (NULL);
	return (line);
}
