/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:34 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/10 16:25:35 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define WIDTH	1600
# define HEIGHT	900
# define SIDE_X	0
# define SIDE_Y	1

enum e_bool
{
	false,
	true
};

enum e_keys
{
	key_a = 0,
	key_s = 1,
	key_d = 2,
	key_w = 13,
	key_esc = 53,
	key_left = 123,
	key_right = 124
};

enum e_direction
{
	east,
	west,
	south,
	north
};

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		buffer[HEIGHT][WIDTH];
}				t_win;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_texture
{
	int		east[64 * 64];
	int		west[64 * 64];
	int		north[64 * 64];
	int		south[64 * 64];
}				t_texture;

typedef struct s_vars
{
	double	raydir_x;
	double	raydir_y;
	double	start_x;
	double	start_y;
	double	grad_x;
	double	grad_y;
	double	prep_wall_dist;
	int		cur_x;
	int		cur_y;
	int		step_x;
	int		step_y;
	int		side;
	int		color;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_start;

}				t_vars;

typedef struct s_info
{
	t_win		win;
	t_player	p;
	t_texture	t;
	t_img		screen;
}				t_info;

#endif
