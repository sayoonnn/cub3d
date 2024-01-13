/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:33:17 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/12 20:33:19 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	move_fore_back(int key, t_player *p)
{
	double	dx;
	double	dy;

	dx = p->dir_x * p->move_speed;
	dy = p->dir_y * p->move_speed;
	if (key == key_w)
	{
		if (!worldMap[(int)(p->pos_x + dx)][(int)(p->pos_y)])
			p->pos_x += dx;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y + dy)])
			p->pos_y += dy;
	}
	if (key == key_s)
	{
		if (!worldMap[(int)(p->pos_x - dx)][(int)(p->pos_y)])
			p->pos_x -= dx;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y - dy)])
			p->pos_y -= dy;
	}
}

static void	move_left_right(int key, t_player *p)
{
	double	dx;
	double	dy;

	dx = p->cam_x * p->move_speed;
	dy = p->cam_y * p->move_speed;
	if (key == key_a)
	{
		if (!worldMap[(int)(p->pos_x - dx)][(int)(p->pos_y)])
			p->pos_x -= dx;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y - dy)])
			p->pos_y -= dy;
	}
	if (key == key_d)
	{
		if (!worldMap[(int)(p->pos_x + dx)][(int)(p->pos_y)])
			p->pos_x += dx;
		if (!worldMap[(int)(p->pos_x)][(int)(p->pos_y + dy)])
			p->pos_y += dy;
	}
}

static void	rotate_cam(int key, t_player *p)
{
	double	prev_dir_x;
	double	prev_cam_x;
	double	rs;

	prev_dir_x = p->dir_x;
	prev_cam_x = p->cam_x;
	rs = p->rot_speed;
	if (key == key_right)
	{
		p->dir_x = p->dir_x * cos(-rs) - p->dir_y * sin(-rs);
		p->dir_y = prev_dir_x * sin(-rs) + p->dir_y * cos(-rs);
		p->cam_x = p->cam_x * cos(-rs) - p->cam_y * sin(-rs);
		p->cam_y = prev_cam_x * sin(-rs) + p->cam_y * cos(-rs);
	}
	if (key == key_left)
	{
		p->dir_x = p->dir_x * cos(rs) - p->dir_y * sin(rs);
		p->dir_y = prev_dir_x * sin(rs) + p->dir_y * cos(rs);
		p->cam_x = p->cam_x * cos(rs) - p->cam_y * sin(rs);
		p->cam_y = prev_cam_x * sin(rs) + p->cam_y * cos(rs);
	}
}

int	key_press(int key, t_info *info)
{
	if (key == key_w || key == key_s)
		move_fore_back(key, &info->p);
	else if (key == key_a || key == key_d)
		move_left_right(key, &info->p);
	else if (key == key_left || key == key_right)
		rotate_cam(key, &info->p);
	else if (key == key_esc)
		exit_cub3d(info);
	mlx_clear_window(info->win.mlx, info->win.win);
	draw_screen(info);
	return (0);
}

int	exit_cub3d(t_info *info)
{
	mlx_destroy_image(info->win.mlx, info->screen.img);
	mlx_destroy_window(info->win.mlx, info->win.win);
	exit(0);
	return (1);
}
