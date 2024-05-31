/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:19:38 by capapes           #+#    #+#             */
/*   Updated: 2024/01/26 20:49:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
||	SYNOPSIS
||     #include <string.h>
||
||     int
||     memcmp(const void *s1, const void *s2, size_t n);
||
||	DESCRIPTION
||     	The memcmp() function compares byte string s1 against byte string s2.  
||		Both strings are assumed to be n bytes long.
||
||	RETURN VALUES
||     The memcmp() function returns zero if the two strings are identical, 
||     otherwise returns the difference between the first two differing bytes 
||	   (treated as unsigned char values, so that `\200' is greater than `\0',
||     for example).
||     Zero-length strings are always identical.  
||     This behavior is not required by C and portable code should only depend
||     on the sign of the returned value.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (++i < n)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (0);
}
