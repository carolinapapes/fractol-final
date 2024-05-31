/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:11 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 19:00:13 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;
	int	i;
	int	c;

	if (n < 0)
		write (fd, "-", 1);
	i = 1000000000;
	mod = n;
	while (i)
	{
		div = mod / i;
		mod = mod % i;
		if (n / i != 0)
		{
			if (div < 0)
				div = -div;
			c = div + '0';
			write(fd, &c, 1);
		}
		i /= 10;
	}
	if (n == 0)
		write (fd, "0", 1);
}
