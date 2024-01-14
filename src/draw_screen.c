/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:31 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/10 16:40:32 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	init_buffer(int buffer[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			buffer[i][j] = 0;
	}
}

void	draw_screen(t_info *info)
{
	t_vars	v;
	int		x;

	x = 0;
	init_buffer(info->win.buffer);
	while (x < WIDTH)
	{
		draw_wall(info, &v, x);
		draw_floor_ceil(&v, &info->win, &info->map, x);
		x++;
	}
	print_screen(&info->win, &info->screen);
}
