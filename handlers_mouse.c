/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:46:50 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:45:10 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hmouse_pointer(int x, int y, t_vars *vars)
{
	int	i;

	i = -6;
	while (++i < 6)
	{
		hmlx_pixel_put(vars, x + i, y, 0x00555555);
		hmlx_pixel_put(vars, x, y + i, 0x00555555);
	}
}

int	hmouse_scroll(int button, int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (double)x * vars->viewport.pixel_size + vars->viewport.origin_x;
	mouse_y = (double)y * vars->viewport.pixel_size - vars->viewport.origin_y;
	hmouse_pointer(x, y, vars);
	if (button == 5)
	{
		if (vars->viewport.pixel_size > 1e24)
			return (0);
		vars->viewport.pixel_size *= 1.05;
	}
	else if (button == 4)
	{
		if (vars->viewport.pixel_size < 1e-24)
			return (0);
		vars->viewport.pixel_size /= 1.05;
	}
	else
		return (0);
	vars->viewport.origin_x = mouse_x - ((double)x * vars->viewport.pixel_size);
	vars->viewport.origin_y = -mouse_y \
		+ ((double)y * vars->viewport.pixel_size);
	fractal_new(vars);
	return (0);
}
