/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:22:33 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/10 18:28:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_buff(int fd, char *self, char *trail, ssize_t *fetch);
static char	*read_till_done(int fd, char *trail);
static char	*extract_line(char **from, char *trail);
static void	*ft_memset(void *s, int c, size_t n);

char	*get_next_line(int fd)
{
	char		*line;
	char		*hold;
	static char	trail[BUFFER_SIZE + 1U];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	trail[BUFFER_SIZE] = 0;
	hold = read_till_done(fd, trail);
	if (!hold)
		return (NULL);
	line = extract_line(&hold, trail);
	free(hold);
	return (line);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dummy;

	dummy = (unsigned char *)s;
	while (n--)
		dummy[n] = c;
	return (s);
}

char	*read_to_buff(int fd, char *self, char *trail, ssize_t *fetch)
{
	char	*temp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	*fetch = 1;
	while (*fetch > 0 && !ft_strchr(self, '\n'))
	{
		*fetch = read(fd, trail, BUFFER_SIZE);
		if (*fetch == 0 && self && *self)
			return (self);
		if (*fetch <= 0)
		{
			ft_memset(trail, 0, BUFFER_SIZE);
			return (free(self), NULL);
		}
		trail[*fetch] = 0;
		temp = self;
		self = gnl_strjoin(self, trail);
		free(temp);
	}
	return (self);
}

char	*read_till_done(int fd, char *trail)
{
	char	*self;
	ssize_t	fetch;

	self = NULL;
	fetch = 1;
	if (*trail)
		self = gnl_strdup(trail);
	self = read_to_buff(fd, self, trail, &fetch);
	return (self);
}

char	*extract_line(char **from, char *trails)
{
	char	*into;
	char	*nl_address;
	size_t	len;

	nl_address = ft_strchr(*from, '\n');
	if (nl_address)
		len = (size_t)(nl_address - *from + 1);
	else
		len = gnl_strlen(*from);
	into = malloc(sizeof(char) * (len + 1));
	if (!into)
		return (NULL);
	into[len] = 0;
	while (len--)
		into[len] = (*from)[len];
	if (nl_address && *(nl_address + 1))
		ft_strncpy(trails, nl_address + 1, BUFFER_SIZE);
	else
		ft_memset(trails, 0, BUFFER_SIZE);
	return (into);
}
