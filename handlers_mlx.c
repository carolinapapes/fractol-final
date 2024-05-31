/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:52:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:44:01 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libs/minilibx_opengl/mlx.h"
#include "viewport_defs.h"
#include <stdlib.h>

void	hmlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + (y * vars->img.l_len + x * (vars->img.bpp >> 3));
	*(unsigned int *)dst = color;
}

void	hmlx_background(t_vars *vars, int x, int y)
{
	return (hmlx_pixel_put(vars, x, y, vars->viewport.background));
}

int	hmlx_initializate(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (msg_mlx_error(), 1);
	vars->win = mlx_new_window(vars->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	if (vars->win == NULL)
		return (msg_mlx_error(), 1);
	return (0);
}

int	hmlx_close( t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	hmlx_img_blank(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), \
	&(vars->img.l_len), &(vars->img.endian));
	vp_iterate(hmlx_background, vars);
}
