/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:06:41 by anvieira          #+#    #+#             */
/*   Updated: 2023/01/03 15:59:04 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
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
