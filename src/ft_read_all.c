#include "libft.h"

int		ft_read_all(int fd, void **file)
{
	int		size;
	int		rd;
	char	buf[150];
	char	*tmp;

	size = 0;
	tmp = NULL;
	*file = malloc(1);
	while ((rd = read(fd, buf, 150)) && rd != -1)
	{
		tmp = ft_memjoin(*file, size, buf, rd);
		size += rd;
		free(*file);
		*file = tmp;
	}
	if (rd == -1 || !tmp || !*file)
		return (-1);
	return (size);
}
