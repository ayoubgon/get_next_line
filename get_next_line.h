#ifndef GIT_NEXT_LINE_H
#define GIT_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 234
#endif

char    *get_next_line(int fd);
char	*read_from_fd(int fd, char *re_str);
char    *extract_line(char *re_str);
char	*next_line_lift(char *re_str);
size_t  ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif 