/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:38 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/10 19:33:43 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_readfile(char *save, int fd);
int		gnlft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*gnlft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *save);
char	*ft_save(char *save);

#endif