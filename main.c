#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	char *s = "fkahfkh";
	char *st = "";
	char *str;

	fd = open("test.txt", O_RDONLY);
	printf("%s",read_from_fd(fd, st));
	str = get_next_line(fd);
	printf ("%d", fd);
	printf("%s",str);
}
