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
	size_t	stack_len;
	size_t	j;

	len = 0;
	stack_len = ft_strlen(stack);
	while (stack[len] && stack[len] != '\n')
		len++;
	if (!stack[len])
		return (free(stack), NULL);
	rest = malloc((stack_len - len + 1) * sizeof(char));
	ft_bzero(rest, (stack_len - len + 1));
	if (!rest)
		return (NULL);
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
	line = malloc((i + 2) * sizeof(char));
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
	line[i] = 0;
	return (line);
}

char	*read_file(int fd, char *stack)
{
	char		*buffer;
	ssize_t		count;

	if (!stack)
	{
		stack = malloc(sizeof(char));
		ft_bzero(stack, 1);
	}
	if (!stack)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stack), NULL);
	while(((count = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[count] = 0;
		stack = join_free(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if ((count == 0 && ft_strlen(stack) == 0) || count < 0)
		return (free(stack), NULL);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
 		return (free(stack), NULL);
	stack = read_file(fd, stack);
	if (!stack)
		return (NULL);
	line = stack_clean(stack);
	if (!line)
		return (NULL);
//	printf("stack == %s\n", stack);
	stack = stack_rest(stack);
	return (line);
}
