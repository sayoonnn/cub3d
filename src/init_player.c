/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:53:33 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/10 19:53:34 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_location(t_mp *map, int *x, int *y, char *dir)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->len)
	{
		j = -1;
		while (++j < map->hight)
		{
			if (map->map[j][i] == 'N' || map->map[j][i] == 'S' || \
			map->map[j][i] == 'E' || map->map[j][i] == 'W')
			{
				*x = j;
				*y = i;
				*dir = map->map[j][i];
				return ;
			}
		}
	}
}

static void	detect_player_dir_ns(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->cam_x = 0;
		p->cam_y = 0.66;
	}
	if (dir == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->cam_x = 0;
		p->cam_y = -0.66;
	}
}

static void	detect_player_dir_we(t_player *p, char dir)
{
	if (dir == 'E')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->cam_x = 0.66;
		p->cam_y = 0;
	}
	if (dir == 'W')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->cam_x = -0.66;
		p->cam_y = 0;
	}
}

void	init_player(t_player *p, t_mp *map)
{
	int		x;
	int		y;
	char	dir;

	find_location(map, &x, &y, &dir);
	p->pos_x = x + 0.5;
	p->pos_y = y + 0.5;
	if (dir == 'N' || dir == 'S')
		detect_player_dir_ns(p, dir);
	else
		detect_player_dir_we(p, dir);
	p->move_speed = 0.1;
	p->rot_speed = 0.1;
}
