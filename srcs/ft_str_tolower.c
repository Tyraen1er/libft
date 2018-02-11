#include "libft.h"

void	ft_str_tolower(char *str)
{
	--str;
	while (*(++str))
		*str = ft_tolower(*str);
}
