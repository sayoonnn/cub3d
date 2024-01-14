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

static int	load_map_info(int ac, char *av[], t_mp *mp)
{
	if (ac == 1)
	{
		ft_printf(2, "Error\ncub3d: need map file\n");
		return (false);
	}
	if (ac > 2)
	{
		ft_printf(2, "Error\ncub3d: too many map files\n");
		return (false);
	}
	cu_mapping(av[1], mp);
	return (true);
}

int	main(int ac, char **av)
{
	t_info		info;

	if (!load_map_info(ac, av, &info.map))
		return (1);
	info.win.mlx = mlx_init();
	if (!info.win.mlx)
		print_err("malloc: ");
	info.win.win = mlx_new_window(info.win.mlx, WIDTH, HEIGHT, "cub3d");
	if (!info.win.mlx)
		print_err("malloc: ");
	init_screen(&info.win, &info.screen);
	load_texture(&info);
	init_player(&info.p, &info.map);
	draw_screen(&info);
	mlx_hook(info.win.win, KEY_EVENT, 0, key_press, &info);
	mlx_hook(info.win.win, CLOSE_BTN, 0, exit_cub3d, &info);
	mlx_loop(info.win.mlx);
}
