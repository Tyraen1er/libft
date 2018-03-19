#include "libft.h"

void	ft_add_str(char *add, char **str)
{
	char	*ret;

	ret = ft_strjoin(add, *str);
	free(*str);
	*str = ret;
}
