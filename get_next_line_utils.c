/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:15:03 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/17 11:23:01 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_bzero(size_t nitems, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;
	size_t			n;

	n = nitems * size;
	ptr = (void *)malloc(n);
	if (!ptr)
		return (NULL);
	i = 0;
	p = (unsigned char *) ptr;
	while (i < n)
	{
		*p = 0;
		p++;
		i++;
	}
	return (ptr);
}

int	ft_strch(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) + 1;
	while (i < len)
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s[i] = s2 [j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_cpy_rline(char **rline, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		(*rline)[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		(*rline)[i++] = '\n';
	(*rline)[i] = '\0';
}
