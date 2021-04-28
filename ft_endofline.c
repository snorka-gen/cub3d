#include "cub.h"

 void	ft_endofline(char *line, int i)
 {
	 while (line[i] != '\0')
	 {
		 if (line[i] != ' ')
			 ft_check_error("Something get wrong with map\n");
		 i++;
	 }
 }