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

# define WIDTH	720
# define HEIGHT	480
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

typedef struct s_win
{
	void	*mlx;
	void	*win;
}				t_win;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_info
{
	t_win		*win;
	t_player	*p;
}				t_info;

typedef struct s_vars
{
	double	raydir_x;
	double	raydir_y;
	double	dist_x;
	double	dist_y;
	double	grad_x;
	double	grad_y;
	int		cur_x;
	int		cur_y;
	int		step_x;
	int		step_y;
	int		side;
	int		color;
}				t_vars;

#endif
