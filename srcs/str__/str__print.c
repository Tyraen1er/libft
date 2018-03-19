#include "libft.h"

void	str__print()
{
	t_str	*addr;

	addr = (t_str*)(&print - sizeof(void*) * 7);
	ft_putstr(addr.str);
}
