//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "libft.h"

int	ft_intstrchr(const char *s, int c)
{
	char b;
	int i;

	b = (char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != b)
		i++;
	if (s[i] == b)
		return (i);
	return (-1);
}