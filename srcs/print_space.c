/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:20:55 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 09:21:36 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		i_equal(t_stat *tmp, int i, int k)
{
	i = (k == 0) ? ft_sizeint(tmp->under_files) : i;
	i = (k == 1) ? ft_sizeint(tmp->size) : i;
	i = (k == 2 && tmp->creator) ? ft_strlen(tmp->creator) : i;
	i = (k == 3 && tmp->groups) ? ft_strlen(tmp->groups) : i;
	i = (k == 4) ? ft_sizeint(tmp->minor) : i;
	return (i);
}

t_max	*get_max(t_max *max, int k, int j)
{
	max->lgt_uf = (k == 0) ? j : max->lgt_uf;
	max->lgt_size = (k == 1) ? j : max->lgt_size;
	max->lgt_crea = (k == 2) ? j : max->lgt_crea;
	max->lgt_grp = (k == 3) ? j : max->lgt_grp;
	max->lgt_minor = (k == 4) ? j : max->lgt_minor;
	return (max);
}

t_max	*get_space(t_stat *stats, t_max *max)
{
	t_stat	*tmp;
	t_stat	*begin;
	int		i;
	int		j;
	int		k;

	k = 0;
	begin = stats;
	while (k < 5)
	{
		i = 0;
		j = 0;
		tmp = begin;
		while (tmp)
		{
			i = i_equal(tmp, i, k);
			if (j <= i)
				j = i;
			tmp = tmp->next;
		}
		max = get_max(max, k, j);
		k++;
	}
	return (max);
}

void	ft_put_space_int(int uf, int j)
{
	int i;

	i = ft_sizeint(uf);
	while (j > i)
	{
		ft_putchar(' ');
		j--;
	}
	ft_putnbr(uf);
}

void	ft_put_space_str(char *str, int j)
{
	int i;

	i = ft_strlen(str);
	ft_putstr(str);
	while (j > i)
	{
		ft_putchar(' ');
		j--;
	}
}
