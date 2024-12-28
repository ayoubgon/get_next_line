/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adehbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:34 by adehbi            #+#    #+#             */
/*   Updated: 2024/12/28 17:27:39 by adehbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_str_lift(char *re_str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!re_str)
		return (NULL);
	while (re_str[i] && re_str[i] != '\n')
		i++;
	if (!re_str[i])
		return (free (re_str), NULL);
	new_str = malloc((ft_strlen(re_str) - i) + 1);
	if (!new_str)
		return (NULL);
	i++;
	while (re_str[i])
		new_str[j++] = re_str[i++];
	new_str[j] = 0;
	free (re_str);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	str = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[l])
		str[i++] = s2[l++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*string;

	if (!s1)
		return (NULL);
	i = ft_strlen((char *)s1);
	string = malloc(i + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
