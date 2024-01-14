/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:04 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/12 20:40:06 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_image(t_info *info, int *texture, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(info->win.mlx, path, &img.img_width, \
	&img.img_height);
	if (!img.img)
		print_err();
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, \
	&img.endian);
	if (!img.data)
		print_err();
	y = 0;
	while (y < img.img_height)
	{
		x = 0;
		while (x < img.img_width)
		{
			texture[img.img_height * y + x] = img.data[img.img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->win.mlx, img.img);
}

void	load_texture(t_info *info)
{
	load_image(info, info->t.east, info->map.ea);
	load_image(info, info->t.west, info->map.we);
	load_image(info, info->t.south, info->map.so);
	load_image(info, info->t.north, info->map.no);
}

void	init_screen(t_win *win, t_img *screen)
{
	screen->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (!screen->img)
		print_err();
	screen->data = (int *)mlx_get_data_addr(screen->img, &screen->bpp, \
	&screen->size_l, &screen->endian);
	if (!screen->data)
		print_err();
}
