/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:27:10 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 22:27:08 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbrlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (++len && n != 0)
		n /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_getnbrlen(n);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	str[--len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		str[--len] = ((n % 10) * -1 + '0');
		n /= 10;
		n *= -1;
	}
	while (n > 0 && --len >= 0)
	{
		str[len] = (n % 10 + '0');
		n = n / 10;
	}
	return (str);
}
