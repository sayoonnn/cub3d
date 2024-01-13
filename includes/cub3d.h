/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:33:45 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/10 14:33:46 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "types.h"

extern int	worldMap[12][12];

void	draw_screen(t_info *info);
void	draw_wall(t_info *info, t_vars *v, int x);
void	draw_floor_ceil(t_vars *v, t_win *win, int x);
void	print_screen(t_win *win, t_img *screen);
void	init_player(t_player *p);

int		key_press(int key, t_info *info);
int		exit_cub3d(t_info *info);

void	load_texture(t_info *info);
void	init_screen(t_win *win, t_img *screen);

void	print_err(void);

#endif
