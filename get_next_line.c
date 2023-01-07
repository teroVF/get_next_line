/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:38 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/07 01:41:11 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(char *text, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!text)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&text[ft_strlen(text)]);
// 	while (text[i] != '\0')
// 	{
// 		if (text[i] == (char) c)
// 			return ((char *)&text[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *text, char *buf)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*newtext;

// 	if (!text)
// 	{
// 		text = (char *)malloc(1 * sizeof(char));
// 		text[0] = '\0';
// 	}
// 	if (!text || !buf)
// 		return (NULL);
// 	newtext = malloc(sizeof(char) * ((ft_strlen(text) + ft_strlen(buf)) + 1));
// 	if (newtext == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (newtext)
// 		while (text[++i] != '\0')
// 			newtext[i] = text[i];
// 	while (buf[j] != '\0')
// 		newtext[i++] = buf[j++];
// 	newtext[ft_strlen(text) + ft_strlen(buf)] = '\0';
// 	free(text);
// 	return (newtext);
// }

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
	char	*buf;
	int		nr_byte;

	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	nr_byte = 1;
	while (!ft_strchr(text, '\n') && nr_byte)
	{
		nr_byte = read(fd, buf, BUFFER_SIZE);
		if (nr_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		if (nr_byte == 0)
		{
			free(buf);
			return (NULL);
		}

		buf[nr_byte] = '\0';
		text = ft_strjoin(text, buf);
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
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buf = catch_text(fd, buf);
	if (!buf || buf[0] == '\0')
		return (NULL);
	line = get_firstline(buf);
	buf = catch_newtext(buf);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	printf("%d", BUFFER_SIZE);
// 	fd = open("b.txt", O_RDONLY);
// 	printf("%s \n", get_next_line(fd));
// 	return 0;
// }
