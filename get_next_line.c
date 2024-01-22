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

char	*ft_buf_clear(char *buf)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	while (buf[i])
	{
		new[j] = buf[i];
		i++;
		j++;
	}
	new[j] = 0;
	return (new);
}

char	*ft_line_cut(char *line)
{
	char	*new;
	size_t	i;

	i = 0;
	while (line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\n';
	return (new);
}

char	*check_line(char *buf)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*str;

	i = ft_strlen(buf) - 1;
	str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!str)
		return (NULL);
	if (buf[i] == '\n')
	{
		str[0] = 0;
		return (str);
	}
	tmp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	j = 0;
	while (buf[i] != '\n' && buf[i])
		tmp[j++] = buf[i--];
	i = 0;
	while (j && tmp[--j])
		str[i++] = tmp[j];
	str[i] = 0;
	free(tmp);
	return (str);
}

char	*clear_line(char *line)
{
	size_t	len;

	len = ft_strlen(line) - 1;
	while (line[len] != '\n')
	{
		//printf("line[len] == |%c|\n", line[len]);
		line[len] = 0;
		len--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	size_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
 		return (NULL);
	static int	i = 1;
	//printf("buf == |%s|, attempt %d\n", buf, i);
	line = check_line(buf);
	//printf("line == |%s|, attempt %d\n", line, i++);
	while(((count = read(fd, buf, BUFFER_SIZE)) > 0) || (count == 0 && buf[0]))
	{
		buf[count] = 0;
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
		if (ft_strchr(buf, '\n'))
		{
			line = clear_line(line);
			break ;
		}
	}
	if (ft_count_char('\n', line) > 1)
	{
		ft_buf_clear(buf);
		line = ft_line_cut(line);
	}
	//printf("buf == |%s|\n", buf);
	if ((count == 0 && ft_strlen(line) == 0) || count < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}


// char	*ft_line(char *buf)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!buf[i])
// 		return (NULL);
// 	while (buf[i] && buf[i] != '\n')
// 		i++;
// 	line = ft_calloc(i + 1, sizeof(char));
// 	i = 0;
// 	while (buf[i] && buf[i] != '\n')
// 	{
// 		line[i] = buf[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_next(char *buf)
// {
// 	static int		i;
// 	int		j;
// 	char	*line;

// 	i = 0;
// 	while (buf[i] && buf[i] != '\n')
// 		i++;
// 	if (!buf[i])
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// 	line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
// 	i++;
// 	j = 0;
// 	while (buf[i])
// 		line[j++] = buf[i++];
// 	line[j] = '\0';
// 	free(buf);
// 	return (line);
// }

// char	*read_file(int fd, char *str)
// {
// 	char	buf[buf_SIZE + 1];
// 	size_t	i;
// 	char	*tmp;

// 	if (!str)
// 		str = ft_calloc(1, 1);
// 	while ((i = read(fd, buf, buf_SIZE)) > 0)
// 	{
// 		buf[i] = '\0';
// 		tmp = ft_strjoin(str, buf);
// 		free(str);
// 		str = tmp;
// 		if (ft_strchr(buf, '\n'))
// 			break;
// 	}
// 	if ((i == 0 && ft_strlen(str) == 0) || i < 0)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char		*buf;
// 	char		*str;

// 	if (fd < 0 || buf_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	if (!buf)
// 	{
// 		buf = read_file(fd, buf);
// 		if (!buf)
// 			return (NULL);
// 		return (buf);
// 	}
// 	buf = read_file(fd, buf);
// 	printf("buf == %s|\n", buf);
// 	if (!buf)
// 		return (NULL);
// 	//str = ft_line(buf);
// 	buf = ft_next(buf);
// 	return (buf);
// }
