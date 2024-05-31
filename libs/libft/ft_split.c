/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:21:52 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 21:18:24 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_find_substr(char const *s, char c, char **result)
{
	char	*start;
	char	*end;
	int		count;

	count = 1;
	start = (char *)s;
	while (start[0])
	{
		end = ft_strchr(start, c);
		if (end == 0)
			end = (char *)&s[ft_strlen(s)];
		if (end != start)
			count++;
		if (end == (char *)&s[ft_strlen(s)])
			break ;
		start = end + 1;
	}
	result = (char **) malloc(count * sizeof(char *));
	if (!result)
		return (NULL);
	result[--count] = NULL;
	return (result);
}

static char	**ft_free_split(char **mem_to_free, int j)
{
	while (j >= 0)
		free(mem_to_free[j--]);
	free(mem_to_free);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*start;
	char	*end;
	int		i;
	char	**result;

	result = NULL;
	result = ft_find_substr(s, c, result);
	if (!result)
		return (NULL);
	i = -1;
	start = (char *)s;
	while (start[0])
	{
		end = ft_strchr(start, c);
		if (end == 0)
			end = (char *)&s[ft_strlen(s)];
		if (end != start && ++i > -1)
			result[i] = ft_substr(start, (size_t)0, end - start);
		if (end != start && i > -1 && !result[i])
			return (ft_free_split(result, i));
		if (end == (char *)&s[ft_strlen(s)])
			break ;
		start = end + 1;
	}
	return (result);
}
