/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:55:54 by capapes           #+#    #+#             */
/*   Updated: 2024/01/26 21:29:42 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*strjoin;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (strjoin == 0)
		return (0);
	while (++i < s1_len)
		strjoin[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		strjoin[i + s1_len] = s2[i];
	return (strjoin);
}
