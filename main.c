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

int	worldMap[12][12] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,},
	{1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1,},
	{1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,}
						};

int	main(void)
{
	t_info		info;

	info.win.mlx = mlx_init();
	if (!info.win.mlx)
		print_err();
	info.win.win = mlx_new_window(info.win.mlx, WIDTH, HEIGHT, "cub3d");
	if (!info.win.mlx)
		print_err();
	init_screen(&info.win, &info.screen);
	load_texture(&info);
	init_player(&info.p);
	draw_screen(&info);
	mlx_hook(info.win.win, 2, 0, key_press, &info);
	mlx_hook(info.win.win, 17, 0, exit_cub3d, NULL);
	mlx_loop(info.win.mlx);
}
