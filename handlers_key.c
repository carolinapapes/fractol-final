/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:47:31 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:56:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "macros.h"

int	hkeys(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		hmlx_close(vars);
	if (key_code == KEY_H)
		msg_help(1);
	return (0);
}
