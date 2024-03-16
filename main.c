#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (s[i] && i < dstsize - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(src));
}
int test_alloc(char *d)
{
	d = malloc(6);
	d = "ahmed";
	printf("%s\n", d);
	// free(d);
	return(1);
}*/
/*int main()
{
//   char *s="ahmed";
  char *d;
  int rd;
// d = malloc(ft_strlen("ahmed\nbk") + 1);
d = 0;
//   int fd = open("file.txt", O_RDWR | O_CREAT, 0777);
//   write(fd, "ahmed\nbk", 8);
//   close(fd);
//   open("file.txt", O_RDWR);
//   rd = read(fd, d, 7);
d += "7";
// rd = test_alloc(d);
// free(d);
printf("%s\n", d);

}*/

int main()
{
	int fd;
	// char *res;
	// char *buf = calloc (6,1);
	// printf("1");
	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	// printf("fd = %i \n", fd);
	// printf("test");
	// res = get_next_line(fd);
	printf("%s" ,get_next_line(fd));
	printf("-------\n");
	// printf("%s",res);
	printf("%s" ,get_next_line(fd));
	printf("-------\n");
	printf("%s" ,get_next_line(fd));
	// printf("%s" ,get_next_line(fd));
	// printf("-------\n");
	// printf("%s" ,get_next_line(fd));
	// printf("-------\n");
	// printf("%s" ,get_next_line(fd));
	// printf("-------\n");/a	

	// printf("%s" ,get_next_line(fd));
	// free(res);
	// system("leaks a.out");

}