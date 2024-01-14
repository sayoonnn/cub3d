/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_sp_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:40:27 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/14 18:14:27 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

void	msm_ml_copy(t_mp *mp, int min_x, int max_x)
{
	t_md	*now;
	int		i;
	int		j;

	i = 0;
	now = mp->m_data;
	while (i < mp->hight)
	{
		mp->map[i] = malloc(max_x - min_x + 2);
		if ((mp->map)[i] == 0)
			mp_exit("cub3d: malloc error\n", 0);
		j = 0;
		while (j < max_x - min_x + 1)
		{
			if (min_x + j < now->len)
				mp->map[i][j] = (now->line)[min_x + j];
			else
				mp->map[i][j] = ' ';
			j ++;
		}
		mp->map[i][j] = '\0';
		now = now->next;
		i ++;
	}
}

void	msm_malloc(t_mp *mp, int min_x)
{
	int		max_x;
	t_md	*now;
	int		i;

	max_x = 0;
	mp->map = malloc(sizeof(char *) * mp->hight);
	if (mp->map == 0)
		mp_exit("cub3d: malloc error\n", 0);
	now = mp->m_data;
	while (now != 0)
	{
		i = now->len;
		while (now->line[i] == ' ' || now->line[i] == '\0')
			i --;
		if (max_x < i)
			max_x = i;
		now = now->next;
	}
	i = 0;
	mp->len = max_x - min_x + 1;
	while (i < mp->hight)
		(mp->map)[i ++] = 0;
	msm_ml_copy(mp, min_x, max_x);
}

int	msm_lc_min(char **line, t_md **now, int *man)
{
	char	ch;
	int		isok;
	int		min_x;

	min_x = 0;
	isok = 0;
	while ((*line)[(*now)->len] != '\0')
	{
		if (isok == 0 && (*line)[(*now)->len] != ' ')
			isok = 1;
		else if (isok == 0)
			min_x ++;
		else
		{
			ch = (*line)[(*now)->len];
			if (ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
				*man += 1;
			else if (ch != ' ' && ch != '0' && ch != '1')
				mp_exit("cub3d: map file has wrong word(s)\n", line);
		}
		(*now)->len ++;
	}
	if (isok == 0)
		mp_exit("cub3d: map file has empty (or white space) line(s)\n", line);
	return (min_x);
}

int	msm_linecheck(char **line, t_md **now, int *man)
{
	int	min_x;

	*now = malloc(sizeof(t_md));
	if (*now == 0)
		mp_exit("cub3d: malloc error\n", line);
	(*now)->len = 0;
	(*now)->line = 0;
	(*now)->next = 0;
	min_x = msm_lc_min(line, now, man);
	if (*man > 1)
		mp_exit("cub3d: too many player\n", line);
	(*now)->line = *line;
	*line = 0;
	return (min_x);
}

void	mp_sp_map(t_mp *mp, char **line, int fd)
{
	int		l;
	int		man;
	int		min_x;
	t_md	**now;

	man = 0;
	now = &(mp->m_data);
	min_x = msm_linecheck(line, now, &man);
	while (1)
	{
		if (mp->hight >= 2147483647)
			mp_exit("cub3d: map is too big\n", 0);
		now = &((*now)->next);
		*line = mp_gnl(fd, mp);
		if (*line == 0)
			break ;
		l = msm_linecheck(line, now, &man);
		if (min_x > l)
			min_x = l;
		mp->hight ++;
	}
	if (man == 0)
		mp_exit("cub3d: no player\n", 0);
	msm_malloc(mp, min_x);
}
