#include "t_str.h"

t_str	init_str()
{
	t_str	*neo;

	neo = (t_str*)malloc(sizeof(t_str));
	if (allClasses == NULL)
	{
		allClasses = neo;
		neo->id = 0;
		neo->next = NULL;
		neo->_this = neo;
	}
}
