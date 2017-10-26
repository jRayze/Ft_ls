/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:58:09 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/06 17:22:16 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (size == 0)
		return (NULL);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
