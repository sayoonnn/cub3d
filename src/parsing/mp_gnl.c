/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:01:59 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/14 18:16:34 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

char	*mgnl_check(t_mp *mp)
{
	int		i;
	char	*copy;

	if (mp->gnl == 0)
		return (0);
	i = 0;
	while (mp->gnl[i] != '\0' && mp->gnl[i] != '\n')
		i ++;
	if (mp->gnl[i] == '\0')
		return (0);
	copy = malloc(i + 1);
	if (copy == 0)
		mp_exit("cub3d: malloc error\n", 0);
	mgnl_ft_strcpy(mp->gnl, copy, i);
	mgnl_ch_remain(mp, i + 1);
	return (copy);
}

void	mgnl_ch_remain(t_mp *mp, int def)
{
	int		aft;
	char	*remain;

	aft = 0;
	remain = 0;
	while (mp->gnl[def + aft] != '\0')
		aft ++;
	if (aft > 0)
	{
		remain = malloc(aft + 1);
		if (remain == 0)
			mp_exit("cub3d: malloc error\n", 0);
		mgnl_ft_strcpy(&(mp->gnl[def]), remain, aft);
	}
	free(mp->gnl);
	mp->gnl = 0;
	if (aft > 0)
		mp->gnl = remain;
}

void	mgnl_copy(t_mp *mp, char *line, int len)
{
	int		i;
	char	*copy;

	i = 0;
	while (mp->gnl != 0 && mp->gnl[i] != '\0')
		i ++;
	if (line[len - 1] == '\0')
		len --;
	copy = malloc(i + len + 1);
	if (copy == 0)
		mp_exit("cub3d: malloc error\n", 0);
	if (mp->gnl != 0)
		mgnl_ft_strcpy(mp->gnl, copy, i);
	mgnl_ft_strcpy(line, &(copy[i]), len);
	if (mp->gnl != 0)
		free(mp->gnl);
	mp->gnl = copy;
}

char	*mgnl_stop(t_mp *mp)
{
	char	*ret;

	if (mp->gnl != 0)
	{
		ret = mgnl_check(mp);
		if (ret == 0)
		{
			ret = mp->gnl;
			mp->gnl = 0;
		}
		return (ret);
	}
	else
		return (0);
}

char	*mp_gnl(int fd, t_mp *mp)
{
	int		len;
	char	*ret;
	char	line[50];

	ret = 0;
	if (mp->gnl != 0)
	{
		ret = mgnl_check(mp);
		if (ret != 0)
			return (ret);
	}
	while (1)
	{
		len = read(fd, line, 50);
		if (len <= 0)
			break ;
		mgnl_copy(mp, line, len);
		ret = mgnl_check(mp);
		if (ret != 0)
			return (ret);
	}
	return (mgnl_stop(mp));
}
