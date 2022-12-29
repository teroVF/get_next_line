/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:41 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/21 20:44:29 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while ((unsigned char)c != (unsigned char)*str)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char *get_firstline(char *text)
{
	int 	i;
	char	*str;

	if(!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	str = (char*) malloc( (i + 2) * sizeof(char));
	if(!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		{
			str[i] = text[i];
			i++;
		}

	if (text[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *catch_text(int fd, char* text)
{
	char	*buff;
	int		nr_byte;

	buff = (char*) malloc((BUFFER_SIZE + 1) * sizeof(char));
	nr_byte = 1;
	if (!buff)
		return (NULL);

  	while (!ft_strchr(text,'\n') && nr_byte)
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

char	*catch_newtext(char *buf)
{
	int 	i;
	int		j;
	char *str;

	i = 0;
	while(buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	str = (char*) malloc(sizeof(char)*(ft_strlen(buf) - i +1));
	if(!str)
		return(0);
	i++;
	j = 0;
	while(buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(buf);
	return (str);
}
