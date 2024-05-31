/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:06:16 by capapes           #+#    #+#             */
/*   Updated: 2024/01/28 20:38:52 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
||  SYNOPSIS
||       #include <string.h>
||  
||       char *
||       strdup(const char *s1);
||  
||  DESCRIPTION
||		The strdup() function allocates sufficient memory 
||		for a copy of the string s1, does the copy, and returns a pointer to it.
||		The pointer may subsequently be used as an argument to free(3).
||  
||		If insufficient memory is available, 
||		NULL is returned and errno is set to ENOMEM.
*/
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*allocated;
	int		i;

	i = ft_strlen(s1) + 1;
	allocated = malloc (sizeof(char) * i);
	if (allocated == 0)
		return (0);
	ft_memmove(allocated, s1, i);
	return (allocated);
}
