/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:38 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/13 18:58:10 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

int	mp_mp_three(t_mp *mp, int i, int j)
{
	int	a;
	int	ret;

	a = 0;
	ret = 0;
	while (a < 3)
	{
		if (mp->map[i - 1 + a][j] == ' ')
			ret ++;
		a ++;
	}
	return (ret);
}

int	mp_mp_nine(t_mp *mp, int i, int j)
{
	int	a;
	int	ret;

	a = 0;
	ret = 0;
	if (i == 0 || j == 0)
		return (-1);
	while (a < 3)
	{
		ret += mp_mp_three(mp, i, j - 1 + a);
		a ++;
	}
	return (ret);
}

void	mp_mp(t_mp *mp, int i, int j, int def)
{
	while (j < mp->len)
	{
		if ((mp->map[i][j] == '1' || mp->map[i][j] == ' ') && def == 1)
			def = 0;
		else if (mp->map[i][j] == '0' || mp->map[i][j] == 'N' || \
				mp->map[i][j] == 'S' || mp->map[i][j] == 'E' || \
				mp->map[i][j] == 'W')
		{
			if ((def == 0 && mp_mp_nine(mp, i, j) != 0) || \
				(def == 1 && mp_mp_three(mp, i, j + 1) != 0))
				mp_exit("cub3d: the wall isn't close\n", 0);
			else
				def = 1;
		}
		j ++;
	}
}

void	mp_mapping(t_mp *mp)
{
	int	i;

	i = 0;
	while (i < mp->hight)
	{
		mp_mp(mp, i, 0, 0);
		i ++;
	}
}
