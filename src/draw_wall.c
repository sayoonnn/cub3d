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

static void	init_vars(t_vars *v, t_player *p, int x)
{
	v->raydir_x = p->dir_x + p->cam_x * (2 * x / (double)WIDTH - 1);
	v->raydir_y = p->dir_y + p->cam_y * (2 * x / (double)WIDTH - 1);
	v->grad_x = fabs(1 / v->raydir_x);
	v->grad_y = fabs(1 / v->raydir_y);
	if (v->raydir_x < 0)
	{
		v->step_x = -1;
		v->start_x = (p->pos_x - v->cur_x) * v->grad_x;
	}
	else
	{
		v->step_x = 1;
		v->start_x = (v->cur_x + 1.0 - p->pos_x) * v->grad_x;
	}
	if (v->raydir_y < 0)
	{
		v->step_y = -1;
		v->start_y = (p->pos_y - v->cur_y) * v->grad_y;
	}
	else
	{
		v->step_y = 1;
		v->start_y = (v->cur_y + 1.0 - p->pos_y) * v->grad_y;
	}
}

static void	check_wall(t_vars *v)
{
	int	is_hit;

	is_hit = false;
	while (!is_hit)
	{
		if (v->start_x < v->start_y)
		{
			v->start_x += v->grad_x;
			v->cur_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->start_y += v->grad_y;
			v->cur_y += v->step_y;
			v->side = 1;
		}
		if (worldMap[v->cur_x][v->cur_y] > 0)
			is_hit = true;
	}
}

void	detect_texture_pos(t_vars *v, t_player *p)
{
	double	wall_x;

	if (v->side == SIDE_X)
		v->prep_wall_dist = (v->cur_x - p->pos_x + (1 - v->step_x) / 2) \
		/ v->raydir_x;
	else
		v->prep_wall_dist = (v->cur_y - p->pos_y + (1 - v->step_y) / 2) \
		/ v->raydir_y;
	v->line_height = (int)(HEIGHT / v->prep_wall_dist);
	v->draw_start = -(v->line_height) / 2 + HEIGHT / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = v->line_height / 2 + HEIGHT / 2;
	if (v->draw_end >= HEIGHT)
		v->draw_end = HEIGHT - 1;
	if (v->side == 0)
		wall_x = p->pos_y + v->prep_wall_dist * v->raydir_y;
	else
		wall_x = p->pos_x + v->prep_wall_dist * v->raydir_x;
	wall_x -= floor(wall_x);
	v->texture_start = (int)(wall_x * (double)64);
	if (v->side == 0 && v->raydir_x > 0)
		v->texture_start = 64 - v->texture_start - 1;
	if (v->side == 1 && v->raydir_y < 0)
		v->texture_start = 64 - v->texture_start - 1;
}

void	fill_buffer(t_vars *v, t_win *win, t_texture *t, int x)
{
	double	step;
	double	tex_screen_position;
	int		tex_end_point;
	int		y;

	step = 1.0 * 64 / v->line_height;
	tex_screen_position = (v->draw_start - HEIGHT / 2 + v->line_height / 2) \
	* step;
	y = v->draw_start;
	while (y < v->draw_end)
	{
		tex_end_point = (int)tex_screen_position & (64 - 1);
		tex_screen_position += step;
		if (v->side == SIDE_X)
			win->buffer[y][x] = t->west[64 * v->texture_start + tex_end_point];
		else
			win->buffer[y][x] = t->east[64 * v->texture_start + tex_end_point];
		y++;
	}
}

void	draw_wall(t_info *info, t_vars *v, int x)
{
	v->cur_x = (int)info->p.pos_x;
	v->cur_y = (int)info->p.pos_y;
	init_vars(v, &info->p, x);
	check_wall(v);
	detect_texture_pos(v, &info->p);
	fill_buffer(v, &info->win, &info->t, x);
}
