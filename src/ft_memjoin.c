#include "libft.h"

void	*ft_memjoin(void *str1, int a, void *str2, int b)
{
	char	*ret;

	if (!str1 || !str2)
		return (NULL);
	if (!(ret = (char *)malloc(a + b)))
		return (NULL);
	--b;
	while (b + 1)
		ret[a + b] = ((char *)str2)[b--];
	--a;
	while (a + 1)
		ret[a] = ((char *)str1)[a--];
	return (ret);
}
