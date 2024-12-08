#include "get_next_line.h"

char	*read_from_fd(int fd, char *re_str)
{
	char	*buff;
	int		n_byte;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
    n_byte = 1;
	while (!ft_strchr(re_str, '\n') && n_byte != 0)
	{
		n_byte = read (fd, buff, BUFFER_SIZE);
		if (n_byte < 0)
			{
				free(buff);
				return(NULL);
			}
		buff[n_byte] = 0;
		re_str = ft_strjoin(re_str, buff);
	}
	free(buff);
	return (re_str);
}
char    *extract_line(char *re_str)
{
	char	*line;
	int 	i;

	i = 0;
	while (re_str[i] && re_str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	if (re_str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
		i--;
	}
	else
		line[i] = '\0';
	while (i >= 0)
	{
		line[i] = re_str[i];
		i--;
	}
	return (line);
}

char    *get_next_line(int fd)
{
	static char	*re_str;
	char		*line;
	char buff[BUFFER_SIZE + 1];
	int nbyte;

	nbyte = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	while((nbyte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nbyte] = 0;
		re_str = ft_strjoin (re_str, buff);
		if (!re_str)
			return (NULL);
		if (ft_strchr (re_str, '\n'))
			break;
	}
	if (nbyte == -1)
		return(free(re_str), NULL);
	if (!re_str)
		return (NULL);
	line = extract_line(re_str);
	re_str = next_line_lift(re_str);
	return (line);
}


