/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_defs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:15:11 by capapes           #+#    #+#             */
/*   Updated: 2024/05/31 14:42:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_DEFS_H

# define VIEWPORT_DEFS_H

# define WIN_SIZE 600
# define MAX_ITER 150
# define ORIGIN 300
# define PIXEL_SIZE 0.006666
# define MANDELBROT_ORIG_X -396

# define MANDELBROT 0
# define JULIA 1
# define JULIA_SIN 2
# define MANDELBAR 3

static const int	g_palette_summer[10] = {\
0x00005f73, 0x000a9396, 0x00ee9b00, 0x0094d2bd, 0x00e9d8a6, \
0x00ee9b00, 0x00ca6702, 0x00bb3e03, 0x00ae2012, 0x009b2226 \
};

static const int	g_palette_cosmic[10] = {\
0x003a0ca3, 0x00480ca8, 0x00560bad, 0x007209b7, 0x00b5179e, \
0x00f72585, 0x004cc9f0, 0x004895ef, 0x004361ee, 0x003f37c9 \
};

#endif

// # define ORIGIN 0.5 * WIN_SIZE
// # define PIXEL_SIZE 4. / WIN_SIZE
// # define MANDELBROT_ORIG_X -0.66 * WIN_SIZE