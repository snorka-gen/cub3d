/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:51:35 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:51:37 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_check_error("Is mapfile OK?\n");
	close(fd);
}
