#include "libft.h"

void	ft_str_lower(char *str)
{
	--str;
	while (*(++str))
		*str += ('A' <= *str && *str <= 'Z') ? 32 : 0;
}
