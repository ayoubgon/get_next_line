/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <adehbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:36 by adehbi            #+#    #+#             */
/*   Updated: 2025/02/12 16:35:25 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_fd(int fd, char *re_str)
{
	char	*buff;
	int		n_byte;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free (re_str), NULL);
	n_byte = 1;
	while (n_byte != 0)
	{
		n_byte = read (fd, buff, BUFFER_SIZE);
		if (n_byte < 0)
			return (free (buff), free (re_str), NULL);
		buff[n_byte] = '\0';
		re_str = ft_strjoin(re_str, buff);
		if (!re_str)
			return (free (buff), NULL);
		if (ft_strchr(re_str, '\n'))
			break ;
	}
	free(buff);
	return (re_str);
}

char	*extract_line(char *re_str)
{
	char	*line;
	int		i;

	i = 0;
	if (!re_str || !*re_str)
		return (NULL);
	while (re_str[i] && re_str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (free (re_str), NULL);
	if (re_str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	i--;
	while (i >= 0)
	{
		line[i] = re_str[i];
		i--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*re_str[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	re_str[fd] = read_from_fd(fd, re_str[fd]);
	if (!re_str[fd])
		return (NULL);
	line = extract_line(re_str[fd]);
	re_str[fd] = next_str_lift(re_str[fd]);
	return (line);
}
