/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 12:44:11 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"
#include "viewport_defs.h"

int	eq_mandelbrot(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = 2 * *x * *y + *y0;
	*x = *x * *x - *y * *y + *x0;
	*y = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_julia(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = *x * *x - *y * *y + *x0;
	*y = 2 * *x * *y + *y0;
	*x = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_mandelbar(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = *y0 - 2 * *x * *y;
	*x = *x * *x - *y * *y + *x0;
	*y = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_julia_sin(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = sin(*x) * cosh(*y) + *y0;
	*x = cos(*x) * sinh(*y) + *x0;
	*y = aux;
	return (fabs(*y) < 50);
}

int	fractal_get(double x0, double y0, t_viewport viewport)
{
	double	x;
	double	y;
	int		i;

	x = x0 * viewport.pixel_size + viewport.origin_x;
	y = y0 * viewport.pixel_size - viewport.origin_y;
	if (viewport.fractal == MANDELBROT || viewport.fractal == MANDELBAR)
	{
		x0 = x;
		y0 = y;
	}
	if (viewport.fractal == JULIA)
	{
		x0 = viewport.julia_var_x;
		y0 = viewport.julia_var_y;
	}
	if (viewport.fractal == JULIA_SIN)
	{
		x0 = viewport.julia_sin_x;
		y0 = viewport.julia_sin_y;
	}
	i = 0;
	while ((viewport.fn)(&y0, &x0, &y, &x) && ++i < viewport.iters)
		;
	return (i);
}
