#include "cub.h"

 void	ft_endofline(char *line, int i)
 {
	 while (line[i] != '\0')
	 {
		 if (line[i] != ' ')
			 ft_check_error(5);
		 i++;
	 }
 }