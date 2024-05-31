/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:56:34 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 20:46:36 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "viewport_defs.h"
#include "./libs/libft/libft.h"
#include <math.h>

int	ft_is_float(char *str)
{
	int	i;
	int	dot;

	dot = 0;
	i = 0;
	if ((*str == '-' || *str == '+') && ft_isdigit(str[1]))
		str++;
	while (ft_isdigit(*str) && ++i < 7)
		str++;
	if (i == 7 || (*str && *str != '.'))
		return (0);
	else if (*str == '.')
		str++;
	i = 0;
	while (ft_isdigit(*str) && ++i < 7)
		str++;
	if (i == 7 || *str)
		return (0);
	return (1);
}

double	ft_atof(char *str)
{
	double	n;
	double	d;
	int		i;
	int		decimals;
	int		sign;

	n = 0;
	d = 0;
	decimals = 0;
	sign = 1;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ++i)
		sign = -1;
	while (str[i] && str[i] != '.')
		n = n * 10 + str[i++] - '0';
	if (str[i++] == '.')
		while (str[i] && ++decimals)
			d = d * 10 + str[i++] - '0';
	if (decimals)
		d = d / pow(10, decimals);
	return ((n + d) * sign);
}

int	parse_julia(int argc, char **argv, t_vars *vars)
{
	if (argc == 4)
	{
		if (!ft_is_float(argv[2]) || !ft_is_float(argv[3]))
			return (0);
		vars->viewport.julia_var_x = ft_atof(argv[2]);
		vars->viewport.julia_var_y = ft_atof(argv[3]);
	}
	return (1);
}

int	parse_julia_sin(int argc, char **argv, t_vars *vars)
{
	if (argc == 4)
	{
		if (!ft_is_float(argv[2]) || !ft_is_float(argv[3]))
			return (0);
		vars->viewport.julia_sin_x = ft_atof(argv[2]);
		vars->viewport.julia_sin_y = ft_atof(argv[3]);
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_vars *vars)
{
	vp_initiate(vars);
	if (argc == 1 || argc > 4)
		return ;
	if (argc == 2 && !ft_strncmp("mandelbrot", (const char *)argv[1], 11))
		vars->viewport.fractal = MANDELBROT;
	else if ((argc == 2 || argc == 4) \
		&& !ft_strncmp("julia", (const char *)argv[1], 6) \
		&& parse_julia(argc, argv, vars))
		vars->viewport.fractal = JULIA;
	else if ((argc == 2 || argc == 4) \
		&& !ft_strncmp("julia_sin", (const char *)argv[1], 10) \
		&& parse_julia_sin(argc, argv, vars))
		vars->viewport.fractal = JULIA_SIN;
	else if (argc == 2 && !ft_strncmp("mandelbar", (const char *)argv[1], 10))
		vars->viewport.fractal = MANDELBAR;
	return ;
}
