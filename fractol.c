/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:34:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:48:02 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"

void	fractal_put(t_vars *vars, int x, int y)
{
	int	i;

	i = fractal_get(x, y, vars->viewport);
	if (i != vars->viewport.iters)
		hmlx_pixel_put(vars, x, y, palette_get(vars->viewport.palette, i));
}

void	fractal_new(t_vars *vars)
{
	hmlx_img_blank(vars);
	vp_iterate(fractal_put, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

int	main(int argc, char **argv)
{
	t_vars			vars;

	parse_args(argc, argv, &vars);
	if (vars.viewport.fractal == -1)
		return (msg_error_args(), 1);
	if (hmlx_initializate(&vars))
		return (1);
	vp_set(&vars, vars.viewport.fractal);
	fractal_new(&vars);
	mlx_key_hook(vars.win, hkeys, &vars);
	mlx_hook(vars.win, 17, 0, hmlx_close, &vars);
	mlx_mouse_hook(vars.win, hmouse_scroll, &vars);
	mlx_loop(vars.mlx);
}
