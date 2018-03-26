#include "t_str.h"

void	str__print()
{
	t_str	*addr;

	addr = (t_str*)(&print - sizeof(void*) * 7);
	ft_putstr(addr->str);
}

typedef struct					s_str
{
	char						*str;
	struct s_str				*addr;
	int							(*strlen)();
	void						(*lower)();
	void						(*upper)();
	char						(*stradd)(char *);
	char						(*addstr)(char *);
	void						(*print)();
}								t_str;

print
