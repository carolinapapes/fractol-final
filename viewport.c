/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:38 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 12:21:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"
#include "viewport_defs.h"

void	vp_fractal_select(t_viewport *viewport, int set)
{
	if (set == MANDELBROT)
		viewport->fn = eq_mandelbrot;
	else if (set == JULIA)
		viewport->fn = eq_julia;
	else if (set == JULIA_SIN)
		viewport->fn = eq_julia_sin;
	else if (set == MANDELBAR)
		viewport->fn = eq_mandelbar;
}

void	vp_set(t_vars *vars, int fractal)
{
	vars->viewport.pixel_size = PIXEL_SIZE;
	if (fractal == JULIA_SIN)
		vars->viewport.pixel_size = 0.015;
	vars->viewport.origin_x = -ORIGIN * vars->viewport.pixel_size;
	if (fractal == MANDELBROT || fractal == MANDELBAR)
		vars->viewport.origin_x = MANDELBROT_ORIG_X * vars->viewport.pixel_size;
	vars->viewport.origin_y = ORIGIN * vars->viewport.pixel_size;
	vars->viewport.iters = MAX_ITER;
	vars->viewport.fractal = fractal;
	vars->viewport.background = 0x00FFFFFF;
	vars->viewport.palette = 0;
	vp_fractal_select(&vars->viewport, vars->viewport.fractal);
	return ;
}

void	vp_initiate(t_vars *vars)
{
	vars->viewport.fractal = -1;
	vars->viewport.julia_var_x = -0.7;
	vars->viewport.julia_var_y = 0.27015;
	vars->viewport.julia_sin_x = 1;
	vars->viewport.julia_sin_y = 0.2;
}

void	vp_iterate(void (*fn)(t_vars *vars, int x, int y), t_vars *vars)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
			fn(vars, x, y);
	}
	return ;
}
