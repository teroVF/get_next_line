/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:41 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/06 20:31:25 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *text, int c)
{
	int	i;

	i = 0;
	if (!text)
		return (0);
	if (c == '\0')
		return ((char *)&text[ft_strlen(text)]);
	while (text[i] != '\0')
	{
		if (text[i] == (char) c)
			return ((char *)&text[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *text, char *buf)
{
	size_t	i;
	size_t	j;
	char	*newtext;

	if (!text)
	{
		text = (char *)malloc(1 * sizeof(char));
		text[0] = '\0';
	}
	if (!text || !buf)
		return (NULL);
	newtext = malloc(sizeof(char) * ((ft_strlen(text) + ft_strlen(buf)) + 1));
	if (newtext == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (newtext)
		while (text[++i] != '\0')
			newtext[i] = text[i];
	while (buf[j] != '\0')
		newtext[i++] = buf[j++];
	newtext[ft_strlen(text) + ft_strlen(buf)] = '\0';
	free(text);
	return (newtext);
}
