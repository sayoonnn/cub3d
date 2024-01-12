/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:40 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/12 17:05:41 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_screen(t_win *win, t_img *screen)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			screen->data[y * WIDTH + x] = win->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, screen->img, 0, 0);
}
