/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:45:03 by jamerlin          #+#    #+#             */
/*   Updated: 2017/04/12 17:29:56 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*buff;

	buff = (char *)b;
	i = 0;
	while (i < len)
	{
		buff[i] = c;
		i++;
	}
	return (buff);
}
