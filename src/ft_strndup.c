#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = (char *)malloc(++n);
	if (dup == NULL)
		return (NULL);
    dup[--n] = 0;
	while (n--)
		dup[n] = str[n];
	return (dup);
}
