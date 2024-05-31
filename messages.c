/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:37:04 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 15:01:50 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/libft/libft.h"

void	msg_mlx_error(void)
{
	ft_putstr_fd("Mlx error", 2);
}

void	msg_help(int fd)
{
	ft_putstr_fd("-----------------------------------------------------\n", fd);
	ft_putstr_fd("FRACT-OL\n", fd);
	ft_putstr_fd("-----------------------------------------------------\n", fd);
	ft_putstr_fd(" basic: mandelbrot | julia <r> <i> \n", fd);
	ft_putstr_fd(" bonus: julia_sin <r> <i>| mandelbar\n", fd);
	ft_putstr_fd(" <r> <i> optional. Format +/- 012345.012345\n", fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd(" basic: h\t\t\thelp\n", fd);
	ft_putstr_fd(" basic: wheel\t\t\tzoom\n", fd);
	ft_putstr_fd(" bonus: z\t\t\tchange fractal\n", fd);
	ft_putstr_fd(" bonus: c\t\t\tchange colors\n", fd);
	ft_putstr_fd(" bonus: + | -\t\t\titr nbr\n", fd);
	ft_putstr_fd(" bonus: arrows\t\t\tmove\n", fd);
}

void	msg_error_args(void)
{
	ft_putstr_fd("Error, please initiate with at leat one argument\n", 2);
	msg_help(2);
}
