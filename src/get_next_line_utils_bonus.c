/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:11 by jonathro          #+#    #+#             */
/*   Updated: 2024/12/14 18:22:49 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_find_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*t_s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	t_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		t_s[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		t_s[j++] = s2[i++];
	t_s[j] = '\0';
	free(s1);
	return (t_s);
}
