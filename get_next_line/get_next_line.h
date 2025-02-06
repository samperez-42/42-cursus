/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:57:30 by samperez          #+#    #+#             */
/*   Updated: 2024/11/21 12:14:16 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*free_mem(char **ptr);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
#endif