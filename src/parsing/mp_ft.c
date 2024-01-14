/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:43:15 by sinkang           #+#    #+#             */
/*   Updated: 2024/01/13 21:44:41 by sinkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu_mapping.h"

int	mp_ft_word(char *line, int i, char *word)
{
	int	j;

	j = 0;
	while (line[i + j] == word[j])
	{
		if (word[j + 1] == '\0')
			return (1);
		j ++;
	}
	return (0);
}

int	mp_ft_next(char *line, int i)
{
	while (line[i] == ' ')
		i ++;
	while (line[i] != ' ' && line[i] != '\0')
		i ++;
	while (line[i] == ' ')
		i ++;
	if (line[i] == '\0')
		return (0);
	return (i);
}
