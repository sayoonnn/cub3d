/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:55:56 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/14 18:16:32 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

void	mp_set(t_mp *mp)
{
	mp->gnl = 0;
	mp->no = 0;
	mp->so = 0;
	mp->we = 0;
	mp->ea = 0;
	mp->len = 0;
	mp->hight = 1;
	mp->f = -1;
	mp->c = -1;
	mp->map = 0;
	mp->m_data = 0;
	mp_free(mp);
}

void	mp_isnameok(char *name)
{
	int	i;
	int	ii;

	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '.' && i != 0 && name[i - 1] != '\\')
		{
			ii = 0;
			while (name[i + ii] == ".cub"[ii])
			{
				if (ii == 4)
					return ;
				ii ++;
			}
		}
		i ++;
	}
	mp_exit("cub3d: file format is not '.cub'.", 0);
}

int	mp_open(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		mp_exit("cub3d: the file is not exist.", 0);
	return (fd);
}

void	mp_isdataok(t_mp *mp)
{
	if (mp->no == 0 || mp->so == 0 || mp->ea == 0 || mp->ea == 0 || \
		mp->len < 3 || mp->hight < 3 || mp->f == -1 || mp->c == -1)
		mp_exit("cub3d: some infomation is missing.", 0);
}

void	cu_mapping(char *name, t_mp *mp)
{
	mp_set(mp);
	mp_isnameok(name);
	mp_sprit(mp_open(name), mp);
	mp_isdataok(mp);
	mp_mapping(mp);
}
