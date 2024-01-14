/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:04:00 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/11 11:04:03 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	draw_floor_ceil(t_vars *v, t_win *win, t_mp *map, int x)
{
	int	y;

	if (v->draw_end < 0)
		v->draw_end = HEIGHT;
	y = v->draw_end + 1;
	while (y < HEIGHT)
	{
		win->buffer[y][x] = map->f;
		win->buffer[HEIGHT - y][x] = map->c;
		y++;
	}
}
