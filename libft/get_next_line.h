/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:57:30 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 14:47:34 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*free_memory(char **ptr);
char	*ft_gnl_strdup(char *s);
int		ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif