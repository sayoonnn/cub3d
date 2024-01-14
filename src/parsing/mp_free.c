/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:43:59 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/13 21:19:42 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

void	mp_fr_str(char **t)
{
	if (*t != 0)
	{
		free(*t);
		*t = 0;
	}
}

void	mp_fr_data(t_md *data)
{
	t_md	*next;

	while (data != 0)
	{
		mp_fr_str(&(data->line));
		next = data->next;
		free(data);
		data = next;
	}
}

void	mp_fr_map(char **map, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		mp_fr_str(&(map[i]));
		i ++;
	}
	free(map);
}

void	mp_free(t_mp *mp)
{
	static t_mp	*save;

	if (mp != 0)
		save = mp;
	else
	{
		if (save->map != 0)
			mp_fr_map(save->map, save->hight);
		save->map = 0;
		if (save->m_data != 0)
			mp_fr_data(save->m_data);
		save->m_data = 0;
		mp_fr_str(&(save->no));
		mp_fr_str(&(save->so));
		mp_fr_str(&(save->we));
		mp_fr_str(&(save->ea));
		mp_fr_str(&(save->gnl));
	}
}

void	mp_exit(char *err, char **fr)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (err[i] != '\0')
		i ++;
	write(2, err, i);
	if (fr != 0)
	{
		free(*fr);
		*fr = 0;
	}
	mp_free(0);
	exit(1);
}
