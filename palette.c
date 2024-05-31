/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:02:42 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 12:46:09 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport_defs.h"

int	palette_get(int palette, int iteration)
{
	if (palette == 0)
		return (g_palette_summer[iteration % 10]);
	if (palette == 1)
		return (g_palette_cosmic[iteration % 10]);
	return (iteration * 0x00050505);
}
