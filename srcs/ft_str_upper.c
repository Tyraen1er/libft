#include "t_str.h"

void	ft_str_upper(char *str)
{
	--str;
	while (*(++str))
		*str -= ('A' <= *str && *str <= 'Z') ? 32 : 0;
}
