/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:47:31 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:55:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "macros.h"

void	hkey_move(int key_code, t_vars *vars)
{
	double	delta;

	delta = vars->viewport.pixel_size * 10;
	if (key_code == KEY_UP)
		vars->viewport.origin_y -= delta;
	if (key_code == KEY_DOWN)
		vars->viewport.origin_y += delta;
	if (key_code == KEY_LEFT)
		vars->viewport.origin_x += delta;
	if (key_code == KEY_RIGHT)
		vars->viewport.origin_x -= delta;
	fractal_new(vars);
}

void	hkey_iter(int key_code, t_vars *vars)
{
	if (key_code == KEY_PLU)
		vars->viewport.iters += 3;
	if (key_code == KEY_MIN)
		vars->viewport.iters -= 3;
	fractal_new(vars);
}

void	hkey_change(t_vars *vars)
{
	vp_set(vars, (vars->viewport.fractal + 1) % 4);
	fractal_new(vars);
}

void	hkey_change_color(t_vars *vars)
{
	int	palette;

	palette = (vars->viewport.palette + 1) % 3;
	vars->viewport.palette = palette;
	fractal_new(vars);
}

int	hkeys(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		hmlx_close(vars);
	if (key_code == KEY_UP || key_code == KEY_DOWN
		|| key_code == KEY_LEFT || key_code == KEY_RIGHT)
		hkey_move(key_code, vars);
	if (key_code == KEY_PLU || key_code == KEY_MIN)
		hkey_iter(key_code, vars);
	if (key_code == KEY_Z)
		hkey_change(vars);
	if (key_code == KEY_X)
		hkey_change_color(vars);
	if (key_code == KEY_H)
		msg_help(1);
	return (0);
}
