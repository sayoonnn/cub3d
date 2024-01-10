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

# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "types.h"

extern int	worldMap[24][24];

void	draw_screen(t_win *win, t_player *p);
void	init_player(t_player *p);

#endif
