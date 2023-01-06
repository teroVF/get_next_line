/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:38 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/05 23:56:12 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_firstline(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i])
	{
		str[i] = text[i];
		i++;
		if (text[i -1] == '\n')
			break ;
	}
	str[i] = '\0';
	return (str);
}

static char	*catch_text(int fd, char *text)
{
	char	*buff;
	int		nr_byte;

	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nr_byte = 1;
	while (!ft_strchr(text, '\n') && nr_byte)
	{
		nr_byte = read(fd, buff, BUFFER_SIZE);
		if (nr_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nr_byte] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
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
		return (0);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!str)
		return (0);
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
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buf = catch_text(fd, buf);
	if (buf[0] == '\0')
		return (NULL);
	line = get_firstline(buf);
	buf = catch_newtext(buf);
	return (line);
}
