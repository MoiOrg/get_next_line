/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:16:17 by kiparis           #+#    #+#             */
/*   Updated: 2024/01/26 15:40:14 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
    int		fd;
	int		i = 1;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
    {
        printf("Error opening file");
        return 1;
	}
	while ((str = get_next_line(fd)))
	{
		printf("get_next_line == |%s| attempt %d\n", str, i++);
		free(str);
		str = NULL;
	}
    close(fd);
    return 0;
}
