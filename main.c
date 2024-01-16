/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:16:17 by kiparis           #+#    #+#             */
/*   Updated: 2024/01/16 10:43:42 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int	main(void)
{
    int		fd;
	int		i;
	char	*str;

	i = 0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
    }
	while (i < 10)
	{
		str = get_next_line(fd);
		ft_putstr(str);
		free(str);
		i++;
	}
	write(1, "c", 1);
    close(fd);
    return 0;
}