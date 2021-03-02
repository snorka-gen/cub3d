/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:52:40 by fcassey           #+#    #+#             */
/*   Updated: 2021/01/19 16:53:26 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		new_line_is_here(char *str);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_line(char *str);
char	*get_str(char *str);

#endif
