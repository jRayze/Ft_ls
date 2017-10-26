/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:01:18 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/06 17:22:33 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*refresh;
	int		i;

	if (!(s))
		return (NULL);
	i = 0;
	refresh = malloc(sizeof(char) * (len + 1));
	if (!(refresh))
		return (NULL);
	while (len--)
	{
		refresh[i] = s[start];
		i++;
		start++;
	}
	refresh[i] = '\0';
	return (refresh);
}
