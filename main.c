#include "libft.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*datafile;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit(-1);
	fd = ft_read_allstr(fd, (void*)&datafile);
	ft_putstr(datafile);
	free(datafile);
	return (0);
}
