/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:59:57 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/11 19:24:05 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_new_line(char *rest)
{
	int	i;

	if (rest == NULL)
		return (-1);
	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_one_line(char *rest)
{
	char	*one_line;
	int		i;

	one_line = 0;
	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			one_line = malloc(i + 2);
			if (!one_line)
			{
				free(rest);
				rest = 0;
				return (0);
			}
			ft_strlcpy(one_line, rest, i + 2);
			break ;
		}
		i++;
	}
	return (one_line);
}

char	*ft_read(char **rest, char **buff, char **one_line, int fd)
{
	int	rd;

	rd = -2;
	while ((check_new_line(*rest) == -1 && rd != 0) 
		|| (check_new_line(*rest) != -1 && rd == -2))
	{
		rd = read(fd, *buff, BUFFER_SIZE);
		buff[0][rd] = 0;
		*rest = ft_strjoin(*rest, *buff);
		if ((check_new_line(*rest) != -1))
		{
			*one_line = ft_one_line(*rest);
			*rest = ft_strdup(*(rest), (check_new_line(*rest) + 1));
			return (*one_line);
		}
	}
	if (ft_strlen(*rest) == 0)
		return (free(*rest), *rest = 0, NULL);
	if (check_new_line(*rest) == -1 && rd == 0)
	{
		*one_line = ft_strdup(*rest, 0);
		*rest = 0;
	}
	return (*one_line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*one_line;
	char		*buff;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(rest[fd]);
		rest[fd] = 0;
		return (NULL);
	}
	one_line = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	one_line = ft_read(&(rest[fd]), &buff, &one_line, fd);
	free(buff);
	buff = 0;
	return (one_line);
}
