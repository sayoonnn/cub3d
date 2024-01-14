/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_mapping.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:18:13 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/13 21:56:44 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CU_MAPPING_H
# define CU_MAPPING_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "types.h"

void	cu_mapping(char *name, t_mp *mp);
void	mp_set(t_mp *mp);
int		mp_open(char *name);
void	mp_isdataok(t_mp *mp);
void	mp_isnameok(char *name);

void	mp_sprit(int fd, t_mp *mp);
int		mp_sp_fc(int *fc, char **line);
int		mp_sp_isdata(char **line, t_mp *mp);
int		mp_sp_wall(char **way, char **line);
int		mp_sp_fc_total(char **line, int *num, int start, int i);

void	mp_sp_map(t_mp *mp, char **line, int fd);
int		msm_linecheck(char **line, t_md **now, int *man);
int		msm_lc_min(char **line, t_md **now, int *man);
void	msm_malloc(t_mp *mp, int min_x);
void	msm_ml_copy(t_mp *mp, int min_x, int max_x);

int		mp_ft_sp_start(char **line, char **way, int *fc);
int		mp_ft_sp_finish(char **line, int start);

void	mp_mapping(t_mp *mp);
int		mp_mp_nine(t_mp *mp, int i, int j);
int		mp_mp_three(t_mp *mp, int i, int j);
void	mp_mp(t_mp *mp, int i, int j, int def);

int		mp_ft_next(char *line, int i);
int		mp_ft_word(char *line, int i, char *word);

void	mp_exit(char *err, char **fr);
void	mp_free(t_mp *mp);
void	mp_fr_str(char **t);
void	mp_fr_data(t_md *data);
void	mp_ft_map(char **map, int hight);

char	*mp_gnl(int fd, t_mp *mp);
char	*mgnl_stop(t_mp *mp);
char	*mgnl_check(t_mp *mp);
void	mgnl_ch_remain(t_mp *mp, int def);
void	mgnl_copy(t_mp *mp, char *line, int len);

void	mgnl_ft_strcpy(char *src, char *cpy, int len);

#endif
