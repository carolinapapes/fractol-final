/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:01:09 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 19:01:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len_needle;
	size_t		len_haystack;
	char		*start;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	start = (char *)haystack;
	len_haystack = ft_strlen(haystack);
	start = ft_strchr(start, needle[0]);
	if (start == 0 || start == (char *)&haystack[len_haystack] || len == 0)
		return (NULL);
	while ((int)ft_strlen(start) - (len_haystack - (int)len) >= len_needle)
	{
		if (ft_strncmp(needle, start, len_needle) == 0)
			return (start);
		start = start + 1;
		start = ft_strchr(start, needle[0]);
		if (start == 0 || start == (char *)&haystack[len_haystack])
			return (NULL);
	}
	return (NULL);
}
