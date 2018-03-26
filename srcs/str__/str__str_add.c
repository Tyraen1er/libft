#include "t_str.h"

void	ft_str_add(char **str, char *add)
{
	char	*ret;

	ret = ft_strjoin(*str, add);
	free(*str);
	*str = ret;
}
