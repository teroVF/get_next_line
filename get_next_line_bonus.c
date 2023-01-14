/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:45:19 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/14 01:11:19 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char *text, char *buf)
{
	char	*temp;

	if (!text)
	{
		text = (char *) malloc(sizeof(char) * 1);
		text[0] = '\0';
	}
	temp = ft_strjoin(text, buf);
	free(text);
	text = 0;
	return (temp);
}


static char	*get_firstline(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*catch_text(int fd, char *text)
{
	char	*buf;
	int		nr_byte;

	buf = (char *) malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buf)
		return (NULL);
	nr_byte = 1;
	while (nr_byte > 0)
	{
		nr_byte = read(fd, buf, BUFFER_SIZE);
		if (nr_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nr_byte] = '\0';
		text = ft_free(text, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (text);
}

static char	*catch_newtext(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = (char *) malloc((sizeof(char) * (ft_strlen(buf) - i)) + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
	{
		free(buf[fd]);
		buf[fd] = 0;
		return (NULL);
	}
	buf[fd] = catch_text(fd, buf[fd]);
	if (!buf[fd])
	{
		free(buf[fd]);
		return (NULL);
	}
	line = get_firstline(buf[fd]);
	buf[fd] = catch_newtext(buf[fd]);
	return (line);
}

