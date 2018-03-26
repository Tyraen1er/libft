#include "t_str.h"

t_str	*str__new(char *str)
{
	t_str	*ret;

	ret = (t_str*)ft_memalloc(sizeof(t_str));
	//ret.strlen = (const void (*)(void))str__strlen;
	//ret.lower = (const void (*)(void))str__lower;
	//ret.upper = (const void (*)(void))str__upper;
	//ret.stradd = (const void (*)(void))str__stradd;
	//ret.addstr = (const void (*)(void))str__addstr;
	ret->print = str__print;
	//ret.split = (const void (*)(void))str__split;
	//ret.replace = (const void (*)(void))str__replace;
	//ret.count = (const void (*)(void))str__count;
	if (str)
		ret->str = ft_strdup(str);
	return (ret);
}
