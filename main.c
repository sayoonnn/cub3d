/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:33:28 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/10 14:33:29 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

static int	main_loop(t_info *info)
{
	draw_screen(info->win, info->p);
	mlx_clear_window(info->win->mlx, info->win->win);
	return (1);
}

int	key_press(int key, t_info *info)
{
	t_player	*p;

	p = info->p;
	printf("%f %f\n", p->pos_x, p->pos_y);
	if (key == key_w)
	{
		if (!worldMap[(int)(p->pos_x + p->dir_x * p->move_speed)][(int)(p->pos_y)])
			p->pos_x += p->dir_x * p->move_speed;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y + p->dir_y * p->move_speed)])
			p->pos_y += p->dir_y * p->move_speed;
	}
	if (key == key_s)
	{
		if (!worldMap[(int)(p->pos_x - p->dir_x * p->move_speed)][(int)(p->pos_y)])
			p->pos_x -= p->dir_x * p->move_speed;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y - p->dir_y * p->move_speed)])
			p->pos_y -= p->dir_y * p->move_speed;
	}
	if (key == key_d)
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_speed) - p->dir_y * sin(-p->rot_speed);
		p->dir_y = oldDirX * sin(-p->rot_speed) + p->dir_y * cos(-p->rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(-p->rot_speed) - p->plane_y * sin(-p->rot_speed);
		p->plane_y = oldPlaneX * sin(-p->rot_speed) + p->plane_y * cos(-p->rot_speed);
	}
	if (key == key_a)
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_speed) - p->dir_y * sin(p->rot_speed);
		p->dir_y = oldDirX * sin(p->rot_speed) + p->dir_y * cos(p->rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot_speed) - p->plane_y * sin(p->rot_speed);
		p->plane_y = oldPlaneX * sin(p->rot_speed) + p->plane_y * cos(p->rot_speed);
	}
	if (key == key_esc)
		exit(0);
	return (0);
}


int	main()
{
	t_win		win;
	t_player	p;
	t_info		info;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, "cub3d");

	info.win = &win;
	info.p = &p;
	init_player(info.p);
	mlx_hook(win.win, 2, 0, key_press, &info);
	mlx_loop_hook(info.win->mlx, main_loop, &info);
	mlx_loop(info.win->mlx);
}
