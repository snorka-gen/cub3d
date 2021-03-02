//
// Created by Аида Сайдашева on 05.02.2021.
//
#include "libft.h"

void	*ft_spacealloc(size_t count, size_t size)
{
	char	*mem;

	mem = (char *)malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, ' ', count * size);
	mem[count] = '\0';
	return ((void *)mem);
}