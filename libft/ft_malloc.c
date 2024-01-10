/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:28:00 by sayoon            #+#    #+#             */
/*   Updated: 2024/01/09 15:28:01 by sayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_malloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
	{
		perror("malloc: ");
		exit(1);
	}
	return (tmp);
}
