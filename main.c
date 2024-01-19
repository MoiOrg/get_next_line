/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:16:17 by kiparis           #+#    #+#             */
/*   Updated: 2024/01/19 15:25:54 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
    int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
    {
        printf("Error opening file");
        return 1;
	}
	while ((str = get_next_line(fd)))
	{
		printf("get_next_line == |%s|\n", str);
	}
    close(fd);
    return 0;
}



/*str de retour
buffer memoire tempon pour remplir str
commencer par mettre le reste qui est dans buffer dans str et clear buffer en
laissant le surplus pour lappel suivant
mettre le \0 en fin de ligne derriere le \n
on peut free le str meme si il y a des données apres le \0*/