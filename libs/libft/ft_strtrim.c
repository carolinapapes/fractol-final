/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:15:01 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 19:02:41 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (i <= len && ft_strchr(set, s1[i]))
		i++;
	if (i > len || !s1 || !set)
		return (ft_strdup(""));
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	result = ft_substr(s1, i, len - i + 1);
	if (!result)
		return (NULL);
	return (result);
}
