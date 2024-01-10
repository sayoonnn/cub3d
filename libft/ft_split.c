/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:58:03 by sayoon            #+#    #+#             */
/*   Updated: 2023/10/07 21:13:30 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_getrow(char *s, char c)
{
	int	row;

	row = 0;
	while (*s)
	{
		if (*s != c && *(s + 1) == c)
			row++;
		s++;
	}
	if (*(s - 1) != c)
		row++;
	return (row);
}

static int	ft_substrlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	if (!*s && *(s - 1) != c)
		len++;
	return (len);
}

static char	**ft_emptyc(char const *s)
{
	char	**tmp;

	if (*s == 0)
	{
		tmp = (char **)ft_malloc(sizeof(char *) * 1);
		tmp[0] = NULL;
		return (tmp);
	}
	else
	{
		tmp = (char **)ft_malloc(sizeof(char *) * 2);
		tmp[0] = ft_strdup(s);
		tmp[1] = NULL;
		return (tmp);
	}
}

char	**ft_split(char const *s, char c)
{
	int		row;
	int		cnt;
	int		idx;
	char	**tmp;

	if (c == 0 || *s == 0)
		return (ft_emptyc(s));
	row = ft_getrow((char *)s, c);
	tmp = (char **)ft_malloc(sizeof(char *) * (row + 1));
	tmp[row] = NULL;
	cnt = 0;
	idx = 0;
	while (cnt < row)
	{
		while (*(s + idx) == c)
			idx++;
		tmp[cnt] = ft_substr(s, idx, ft_substrlen((char *)(s + idx), c));
		idx += ft_substrlen((char *)(s + idx), c);
		cnt++;
	}
	return (tmp);
}
