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

static void	draw_line(t_win *win, t_vars *v, int x, int line_height)
{
	int	start;
	int	end;
	int	color;

	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (v->side == SIDE_X)
		color = 0x00123456;
	else
		color = 0x00123456 / 2;
	while (start <= end)
	{
		mlx_pixel_put(win->mlx, win->win, x, start, color);
		start++;
	}
}

static double	detect_wall(t_vars *v, t_player *p)
{
	int		is_hit;

	is_hit = false;
	while (!is_hit)
	{
		if (v->dist_x < v->dist_y)
		{
			v->dist_x += v->grad_x;
			v->cur_x += v->step_x;
			v->side = SIDE_X;
		}
		else
		{
			v->dist_y += v->grad_y;
			v->cur_y += v->step_y;
			v->side = SIDE_Y;
		}
		if (worldMap[v->cur_x][v->cur_y] > 0)
			is_hit = true;
	}
	if (v->side == SIDE_X)
		return ((v->cur_x - p->pos_x + (1 - v->step_x) / 2) / v->raydir_x);
	else
		return ((v->cur_y - p->pos_y + (1 - v->step_y) / 2) / v->raydir_y);
}

static void	find_first_meet_line(t_vars *v, t_player *p)
{
	if (v->raydir_x < 0)
	{
		v->step_x = -1;
		v->dist_x = (p->pos_x - v->cur_x) * v->grad_x;
	}
	else
	{
		v->step_x = 1;
		v->dist_x = (v->cur_x + 1.0 - p->pos_x) * v->grad_x;
	}
	if (v->raydir_y < 0)
	{
		v->step_y = -1;
		v->dist_y = (p->pos_y - v->cur_y) * v->grad_y;
	}
	else
	{
		v->step_y = 1;
		v->dist_y = (v->cur_y + 1.0 - p->pos_y) * v->grad_y;
	}
}

static void	init_vars(t_vars *v, t_player *p, int x)
{
	v->raydir_x = p->dir_x + p->plane_x * (2 * x / (double)WIDTH - 1);
	v->raydir_y = p->dir_y + p->plane_y * (2 * x / (double)WIDTH - 1);
	v->cur_x = (int)p->pos_x;
	v->cur_y = (int)p->pos_y;
	v->grad_x = fabs(1 / v->raydir_x);
	v->grad_y = fabs(1 / v->raydir_y);
}

void	draw_screen(t_win *win, t_player *p)
{
	int		x;
	int		line_height;
	t_vars	v;

	x = 0;
	while (x < WIDTH)
	{
		init_vars(&v, p, x);
		find_first_meet_line(&v, p);
		line_height = (int)(HEIGHT / detect_wall(&v, p));
		draw_line(win, &v, x, line_height);
		x++;
	}
}
