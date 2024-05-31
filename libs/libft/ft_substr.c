/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:20:36 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 22:28:32 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

static size_t	ft_min(size_t i1, size_t i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int			i;
	size_t		len_cpy;
	char		*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_cpy = ft_min(ft_strlen(&s[(int)start]), len);
	substr = malloc ((len_cpy + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	i = -1;
	while (++i < (int)len_cpy)
		substr[i] = s[start + (int)i];
	substr[i] = '\0';
	return (substr);
}
