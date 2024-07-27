/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:09:10 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/17 10:56:22 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer, int *r);
char	*ft_joinnfree(char *buffer, char *line);
char	*ft_get_line(char *buffer);
void	ft_cpy_rline(char **rline, char *buffer);
char	*ft_get_buffer(char *buffer);
void	*ft_calloc_bzero(size_t nitems, size_t size);
int		ft_strch(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);

#endif