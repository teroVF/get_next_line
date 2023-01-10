/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:38 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/10 23:10:53 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
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

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	int		sizetotal;
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i] != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != 0)
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
// }

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
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
	// free(text); ver isto
	return (str);
}


// }
/* ver o Join */
static char	*catch_text(int fd, char *text)
{
	char	*buf;
	int		nr_byte;

	if (!text)
	{
		text = (char *) malloc(sizeof(char) * 1);
		text[0] = '\0';
	}

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
/* parece bem */
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 /* || check_empty(fd, buf) == 1 */)
		return (NULL);
	buf = catch_text(fd, buf);
	if (!buf /* || buf[0] == '\0' */)
		return (NULL);
	line = get_firstline(buf);
	buf = catch_newtext(buf);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	fd = open("b.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	return 0;
// }
