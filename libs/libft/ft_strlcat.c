/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:15:25 by capapes           #+#    #+#             */
/*   Updated: 2024/01/21 18:13:23 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
||  strlcat() appends string src to the end of dst.  
||  It will append at most dstsize -
||  strlen(dst) - 1 characters.  It will then NUL-terminate,
||	unless dstsize is 0 or the original
||  dst string was longer than dstsize (in practice this 
||	should not happen as it means that
||  either dstsize is incorrect or that dst is not a proper string).
||	If the src and dst strings overlap, the behavior is undefined.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	while (i + 1 + j < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (dstsize < dst_len)
		return (dstsize + src_len);
	return (dst_len + src_len);
}

// retornar dst_len + minimo entre dstsize src_len 
