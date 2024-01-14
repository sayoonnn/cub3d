/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_sprit_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:42:21 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/14 18:18:12 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

int	mp_ft_sp_start(char **line, char **way, int *fc)
{
	int	start;

	if ((way != 0 && *way != 0) || (fc != 0 && *fc != -1))
		mp_exit("cub3d: some elements are duplicated\n", line);
	start = 0;
	while ((*line)[start] == ' ')
		start ++;
	start += 1;
	if (way != 0)
		start ++;
	if ((*line)[start] == '\0')
		start = 0;
	else if ((*line)[start] == ' ')
		start = mp_ft_next(*line, 0);
	if (start == 0)
		mp_exit("cub3d: some elements have no information\n", line);
	return (start);
}

int	mp_ft_sp_finish(char **line, int start)
{
	if (mp_ft_next(*line, start) != 0)
		mp_exit("cub3d: some elements have too many infomation\n", line);
	return (0);
}
