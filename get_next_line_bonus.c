/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:45:19 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/15 15:23:34 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf[fd] = catch_text(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = get_firstline(buf[fd]);
	buf[fd] = catch_newtext(buf[fd]);
	return (line);
}
