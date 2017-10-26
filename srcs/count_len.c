/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:23:53 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 09:53:57 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sizeint(int i)
{
	int len;

	len = 1;
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int		count_elem_list(t_stat *stats)
{
	t_stat	*beg;
	int		i;

	i = 0;
	beg = stats;
	while (beg)
	{
		i++;
		beg = beg->next;
	}
	return (i);
}

int		ft_get_nb_arg(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		len_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
