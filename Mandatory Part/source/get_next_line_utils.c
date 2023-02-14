/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:52:57 by ahovakim          #+#    #+#             */
/*   Updated: 2023/02/14 15:46:38 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (!s2)
		return (0);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (0);
	i = 0;
	while (s1 != NULL && *s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (s2 != NULL && *s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char	*dpl;
	int		len;
	int		i;

	len = ft_strlen(str);
	dpl = (char *)malloc((len + 1) * sizeof(char));
	if (!dpl)
		return (0);
	i = 0;
	while (str[i])
	{
		dpl[i] = str[i];
		++i;
	}
	dpl[i] = '\0';
	return (dpl);
}

char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str;
	while (*s != (char)ch)
	{
		if (!*s)
			return (0);
		++s;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	length;
	size_t	i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	i = 0;
	if ((size_t)start >= length)
		return (ft_strdup(""));
	if (len > length - (size_t)start)
		len = length - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	while (s[i] && i < len)
	{
		res[i] = s[(size_t)start + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
