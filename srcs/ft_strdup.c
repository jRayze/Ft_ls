/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:41:15 by jamerlin          #+#    #+#             */
/*   Updated: 2017/04/12 17:30:51 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = ft_strlen(s1);
	if ((dest = (char *)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
