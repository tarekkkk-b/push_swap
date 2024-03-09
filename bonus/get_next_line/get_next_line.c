/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:05 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 17:18:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(char *save, int fd)
{
	int		rd;
	char	*buffer;

	buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd != 0 && ft_strchr(save, '\n') == 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			if (save)
				free(save);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = gnlft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*print;
	static char	*save[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	save[fd] = ft_readfile(save[fd], fd);
	if (!save[fd])
		return (NULL);
	print = ft_get_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (print);
}
