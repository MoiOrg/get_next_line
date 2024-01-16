/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:29 by kiparis           #+#    #+#             */
/*   Updated: 2024/01/11 15:07:29 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 8
# include <unistd.h>
# include <stdlib.h>


char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int	fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
#endif