/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_sprit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:38:35 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/14 18:16:37 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

int	mp_sp_wall(char **way, char **line)
{
	int	start;
	int	i;
	int	j;

	start = mp_ft_sp_start(line, way, 0);
	i = 0;
	while ((*line)[start + i] != '\0' && (*line)[start + i] != ' ')
		i ++;
	*way = malloc(i + 1);
	if (*way == 0)
		mp_exit("cub3d: malloc error\n", line);
	j = 0;
	while (j < i)
	{
		(*way)[j] = (*line)[start + j];
		j ++;
	}
	(*way)[j] = '\0';
	return (mp_ft_sp_finish(line, start));
}

int	mp_sp_fc_total(char **line, int *num, int start, int i)
{
	int	total;

	if ((*line)[start + i] != ' ' && (*line)[start + i] != '\0')
		mp_exit("cub3d: some elements have wrong information\n", line);
	else if (num[2] == -1)
		mp_exit("cub3d: please put the fc info 'fc 000,000,000'\n", line);
	total = 0;
	i = 0;
	while (i < 3)
	{
		total = total * 256 + num[i];
		i ++;
	}
	return (total);
}

int	mp_sp_fc(int *fc, char **line)
{
	int	num[3];
	int	start;
	int	i;
	int	j;

	start = mp_ft_sp_start(line, 0, fc);
	i = 0;
	j = 0;
	num[0] = 0;
	num[2] = -1;
	while ((*line)[start + i] >= '0' && (*line)[start + i] <= '9')
	{
		num[j] = num[j] * 10 + ((*line)[start + i] - '0');
		i ++;
		if (num[j] > 255)
			mp_exit("cub3d: color number is too big\n", line);
		if ((*line)[start + i] == ',' && j < 2)
		{
			i ++;
			num[++ j] = 0;
		}
	}
	*fc = mp_sp_fc_total(line, num, start, i);
	return (mp_ft_sp_finish(line, start));
}

int	mp_sp_isdata(char **line, t_mp *mp)
{
	int	i;

	i = 0;
	while ((*line)[i] == ' ')
		i ++;
	if (mp_ft_word(*line, i, "NO") == 1)
		return (mp_sp_wall(&(mp->no), line));
	else if (mp_ft_word(*line, i, "SO") == 1)
		return (mp_sp_wall(&(mp->so), line));
	else if (mp_ft_word(*line, i, "WE") == 1)
		return (mp_sp_wall(&(mp->we), line));
	else if (mp_ft_word(*line, i, "EA") == 1)
		return (mp_sp_wall(&(mp->ea), line));
	else if (mp_ft_word(*line, i, "F") == 1)
		return (mp_sp_fc(&(mp->f), line));
	else if (mp_ft_word(*line, i, "C") == 1)
		return (mp_sp_fc(&(mp->c), line));
	else if ((*line)[i] == '1')
		return (-1);
	else if ((*line)[i] != '\0')
		return (-2);
	return (i);
}

void	mp_sprit(int fd, t_mp *mp)
{
	char	*line;
	int		data;

	while (1)
	{
		line = mp_gnl(fd, mp);
		if (line == 0)
			break ;
		data = mp_sp_isdata(&line, mp);
		if (data == -1)
		{
			mp_sp_map(mp, &line, fd);
			mp_fr_data(mp->m_data);
			mp->m_data = 0;
			break ;
		}
		else if (data == -2)
			mp_exit("cub3d: you put the wrong word(s)\n", &line);
		else if (data != 0)
			mp_exit("cub3d: you make the line that is not empty\n", &line);
		free(line);
	}
	close(fd);
}
