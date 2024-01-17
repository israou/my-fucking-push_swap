#include "push_swap.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (n > 0)
	{
		s[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (str);
}
