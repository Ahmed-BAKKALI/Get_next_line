/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:00:06 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/11 19:02:29 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1, int j)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(ft_strlen(s1 + j) * sizeof(char) + 1);
	if (!s2)
	{
		free(s1);
		s1 = 0;
		return (0);
	}
	while (s1[j])
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	s2[i] = '\0';
	free(s1);
	s1 = 0;
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*d;

	i = 0;
	j = 0;
	d = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
	{
		free(s1);
		s1 = 0;
		return (0);
	}
	while (s1 && s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	s1 = 0;
	return (d);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}